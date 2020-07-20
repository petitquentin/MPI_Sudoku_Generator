#include <grid/grid.hpp>
#include <sudoku/sudoku.hpp>
#include <latexGenerator/latexGenerator.hpp>
#include <algorithm>
#include <iostream>

//Latex generator constructor
LatexGenerator::LatexGenerator(){
    this->path = "output.tex";
    this->isStarted = false;
    this->isEnded = false;
    this->isAtSolution = false;
    ofs.open(this->path, std::ofstream::out | std::ofstream::trunc);
}

//Latex generator constructor
LatexGenerator::LatexGenerator(std::string p){
    this->path = p + ".tex";
    this->isStarted = false;
    this->isEnded = false;
    this->isAtSolution = false;
}

//Latex generator destructor
LatexGenerator::~LatexGenerator(){
    if(!(this->isEnded)){
        std::cout << "[WARNING] The endDocument function have not been call before the destructor call." << std::endl;
        this->endDocument();
    }
    ofs.close();
}

void LatexGenerator::startDocument(int nbPuzzle){
    this->nbPuzzle = nbPuzzle;
    this->nbPuzzleAdded = 0;
    this->nbSolutionAdded = 0;
    this->isStarted = true;

    //
    ofs << "\\documentclass{article}" << std::endl;
    ofs << std::endl;
    ofs << "\\usepackage{array, multirow,makecell}" << std::endl;
    ofs << "\\usepackage{geometry}" << std::endl;
    ofs << "\\usepackage{multicol}" << std::endl;
    ofs << "\\usepackage[english]{babel}" << std::endl;
    ofs << "\\usepackage[utf8]{inputenc}" << std::endl;
    ofs << "\\usepackage{hyperref}" << std::endl;

    ofs << std::endl;

    ofs << "\\newlength\\savedwidth" << std::endl;
    ofs << "\\newcommand\\whline{\\noalign{\\global\\savedwidth" << std::endl;
    ofs << "\\arrayrulewidth\\global\\arrayrulewidth 3pt}" << std::endl;
    ofs << "\\hline \\noalign{\\global\\arrayrulewidth" << std::endl;
    ofs << "\\savedwidth}" << std::endl;
    ofs << "}" << std::endl;
    ofs << "\\renewcommand{\\arraystretch}{1.5}" << std::endl;
    ofs << "\\geometry{hmargin=2cm,vmargin=1.5cm}" << std::endl;
    ofs << "\\newcolumntype{M}[1]{>{\\centering\\arraybackslash}m{#1}}" << std::endl;
    ofs << "\\newlength\\savedtinywidth" << std::endl;
    ofs << "\\newcommand\\thline{\\noalign{\\global\\savedtinywidth" << std::endl;
    ofs << "\\arrayrulewidth\\global\\arrayrulewidth 1.5pt}" << std::endl;
    ofs << "\\hline \\noalign{\\global\\arrayrulewidth" << std::endl;
    ofs << "\\savedtinywidth}" << std::endl;
    ofs << "}" << std::endl;
    ofs << "" << std::endl;
    ofs << "" << std::endl;

    ofs << std::endl;

    ofs << "\\begin{document}" << std::endl;
    ofs << "\\title{Sudoku puzzle output}" << std::endl;
    ofs << "\\date{}" << std::endl;
    ofs << "\\author{Quentin Petit}" << std::endl;
    ofs << "" << std::endl;
    ofs << "\\maketitle" << std::endl;
    ofs << "" << std::endl;
}

void LatexGenerator::addSudokuPuzzle(Sudoku * s){
    if(this->isStarted && !(this->isAtSolution) && !(this->isEnded)){
        this->nbPuzzleAdded++;
        if(this->nbPuzzleAdded > this->nbPuzzle){
            std::cout << "[WARNING] Too many puzzles have been added in the document (currently " << this->nbPuzzleAdded << " on " << this->nbPuzzle << ")" << std::endl;
        }

        ofs << "\\huge" << std::endl;
        ofs << "\\section*{\\Huge Sudoku \\#" << this->nbPuzzleAdded<< " \\normalsize Difficulty "<< s->getDifficulty() <<" \\ \\small (soluce page \\pageref{soluce::" << nbPuzzleAdded << "})}" << std::endl;
        ofs << "\\label{puzzle::"<< nbPuzzleAdded<< "}" << std::endl;
        ofs << "\\begin{center}" << std::endl;
        ofs << "\\renewcommand{\\arraystretch}{1.5}" << std::endl;
        ofs << "\\LARGE" << std::endl;
        ofs << "\\begin{tabular}{!{\\vrule width 3pt} M{1cm} | M{1cm} | M{1cm} !{\\vrule width 3pt} M{1cm} | M{1cm} | M{1cm} !{\\vrule width 3pt} M{1cm} | M{1cm} | M{1cm} !{\\vrule width 3pt} }" << std::endl;
        for(int i = 0; i < 9; i ++){
            if(i%3 == 0){
                ofs << "\\whline" << std::endl;
            }else{
                ofs << "\\hline" << std::endl;
            }
            for(int j = 0; j < 9; j++){
                if(s->getSudokuGrid()->getValueInGrid(i,j) != EMPTYVALUE){
                    ofs << s->getSudokuGrid()->getValueInGrid(i,j);
                }else{
                    ofs << " ";
                }
                if(j == 8){
                    ofs << " \\\\" << std::endl;
                }else{
                    ofs << " & ";
                }
            }
        }
        ofs << "\\whline" << std::endl;
        ofs << "\\end{tabular}" << std::endl;
        ofs << "\\end{center} " << std::endl;
        ofs << "\\normalsize" << std::endl;
        ofs << "" << std::endl;
    }else{
        if(!this->isStarted){
            
            std::cout << "[ERROR] The document is not started : impossible to add new puzzle" << std::endl;
            return;
        }
        if((this->isAtSolution)){
            std::cout << "[ERROR] The document is waiting for a solution : impossible to add new puzzle" << std::endl;
            return;
        }
        if((this->isEnded)){
            std::cout << "[ERROR] The document is finished : impossible to add new puzzle" << std::endl;
            return;
        }
        
    }
}


void LatexGenerator::generatePuzzleToSolution(){
    if(this->nbPuzzle != this->nbPuzzleAdded){
        std::cout << "[WARNING] The number of puzzle added is not egal to the expeted one" << std::endl;
    }
    this->nbColumnBreak = 0;
    this->isAtSolution = true;
    ofs << "\\newpage" << std::endl;
    ofs << "\\section*{\\huge Solutions}" << std::endl;
    ofs << "\\begin{multicols}{3}" << std::endl;
    ofs << "\\normalsize" << std::endl;
    ofs << "" << std::endl;
}


void LatexGenerator::addSolution(Sudoku * s){
    if(this->isStarted && (this->isAtSolution) && !(this->isEnded)){
        this->nbSolutionAdded++;
        if(this->nbSolutionAdded > this->nbPuzzleAdded){
            std::cout << "[ERROR] There is more solution than puzzle : impossible to add new solution" << std::endl;
            this->nbSolutionAdded--;
            return;
        }
        ofs << "\\section*{Puzzle \\#" << this->nbSolutionAdded << " \\tiny (page \\pageref{puzzle::" << this->nbSolutionAdded << "})}" << std::endl;

        ofs << "\\label{soluce::"<< this->nbSolutionAdded<< "}" << std::endl;
        ofs << "\\begin{center}" << std::endl;
        ofs << "\\renewcommand{\\arraystretch}{1.5}" << std::endl;
        ofs << "\\small" << std::endl;
        ofs << "\\begin{tabular}{!{\\vrule width 1.5pt} c | c | c !{\\vrule width 1.5pt} c | c | c !{\\vrule width 1.5pt} c | c | c !{\\vrule width 1.5pt} }" << std::endl;
        for(int i = 0; i < 9; i ++){
            if(i%3 == 0){
                ofs << "\\thline" << std::endl;
            }else{
                ofs << "\\hline" << std::endl;
            }
            for(int j = 0; j < 9; j++){
                ofs << s->getCompleteGrid()->getValueInGrid(i,j);
                if(j == 8){
                    ofs << " \\\\" << std::endl;
                }else{
                    ofs << " & ";
                }
            }
        }
        ofs << "\\thline" << std::endl;
        ofs << "\\end{tabular}" << std::endl;
        ofs << "\\end{center} " << std::endl;
        ofs << "\\normalsize" << std::endl;
        ofs << "" << std::endl;
        
        if(this->nbSolutionAdded % 9 == 0){

            ofs << "\\end{multicols}" << std::endl;

            ofs << "\\newpage" << std::endl;
            ofs << "\\section*{\\huge Solutions}" << std::endl;
            ofs << "\\begin{multicols}{3}" << std::endl;
            ofs << "\\normalsize" << std::endl;
            ofs << "" << std::endl;

        }else{
            if(this->nbSolutionAdded % 3 == 0){

                ofs << "\\columnbreak" << std::endl;
                this->nbColumnBreak++;
                ofs << "" << std::endl;

            }
        }
    }else{
        if(!this->isStarted){
            
            std::cout << "[ERROR] The document is not started : impossible to add new solution" << std::endl;
            return;
        }
        if((this->isAtSolution)){
            std::cout << "[ERROR] The document is waiting for a puzzle : impossible to add new solution" << std::endl;
            return;
        }
        if((this->isEnded)){
            std::cout << "[ERROR] The document is finished : impossible to add new solution" << std::endl;
            return;
        }
    }
}


void LatexGenerator::endDocument(){
    this->isEnded = true;
    ofs << "\\columnbreak" << std::endl;
    this->nbColumnBreak++;
    while(this->nbColumnBreak % 3 != 0){
        ofs << "\\columnbreak" << std::endl;
        this->nbColumnBreak++;
    }
    ofs << "" << std::endl;
    ofs << "\\end{multicols}" << std::endl;
    ofs << "This document was generated with the MPI\\_Sudoku\\_Generator program available here: " <<std::endl;

    ofs << "" << std::endl;
    ofs << "\\href{https://github.com/petitquentin/MPI\\_Sudoku\\_Generator}{https://github.com/petitquentin/MPI\\_Sudoku\\_Generator}" << std::endl;

    ofs << "\\end{document}" << std::endl;
}


int LatexGenerator::getNbPuzzleAdded(){
    return nbPuzzleAdded;
}

int LatexGenerator::getNbSolutionAdded(){
    return nbSolutionAdded;
}

int LatexGenerator::getNbPuzzleExpected(){
    return nbPuzzle;
}