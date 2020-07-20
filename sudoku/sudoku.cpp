
#include <sudoku/sudoku.hpp>
#include <grid/grid.hpp>

#include <vector>
#include <iostream>

//Sudoku constructor
Sudoku::Sudoku(){
    sudokuGrid = new Grid();
    completeGrid = new Grid();
}

//Sudoku destructor
Sudoku::~Sudoku(){
    delete sudokuGrid;
    delete completeGrid;
}

//This function calculate the difficulty of the sudoku, we use here the difficulty estimation introduced here https://dlbeer.co.nz/articles/sudoku.html
void Sudoku::calculateDifficulty(){
    Grid tmpGrid;
    difficulty = 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            tmpGrid.setValueInGrid(i, j, this->sudokuGrid->getValueInGrid(i, j));
        }
    }

    int emptySize = this->sudokuGrid->getNumberEmptyElement();

    while(emptySize != 0){
        std::vector<std::vector<int>> empty;
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(tmpGrid.getValueInGrid(i,j) == EMPTYVALUE){
                    std::vector<int> temp;
                    temp.push_back(i * 9 +j);
                    
                    for(int k = 0; k < 9; k++){
                        if(tmpGrid.canBeInsertHere(i, j, tmpGrid.getShuffleValue(k)))
                        {
                        temp.push_back(tmpGrid.getShuffleValue(k));
                        }
                    }

                    empty.push_back(temp);
                }
            }
        }
        if(empty.size() != 0){
            int index = 0;
            for(int i = 1; i < empty.size(); i++){
                if(empty[i].size() < empty[index].size()){
                    index = i;
                }
            }
            tmpGrid.setValueInGrid(empty[index][0]/9, empty[index][0]%9, completeGrid->getValueInGrid(empty[index][0]/9, empty[index][0]%9));
            difficulty += ((empty[index].size()-1)-1) * ((empty[index].size()-1)-1);
            emptySize = empty.size() - 1;
        }else{
            emptySize = 0;
        }
    }
    difficulty *= 100;
    difficulty += this->sudokuGrid->getNumberEmptyElement();
}

//Function that returns the value of the variable difficulty
int Sudoku::getDifficulty(){
    return this->difficulty;
}

//This function is used to generate the Sudoku
void Sudoku::generatePuzzle(){
    //this->sudokuGrid->resetGrid();
    this->sudokuGrid->initializeValideGrid();
    this->sudokuGrid->copyGrid(this->completeGrid);
    this->sudokuGrid->generatePuzzle();
}

//Return a sudoku grid pointer
Grid * Sudoku::getSudokuGrid(){
    return sudokuGrid;
}

//Return a solution grid pointer
Grid * Sudoku::getCompleteGrid(){
    return completeGrid;
}

//This function prints the sudoku grid
void Sudoku::printSudoku(){
    std::cout << "+-----+-----+-----+" << std::endl;
    for(int k = 0; k < 3; k++){
        for(int i = 0; i < 3; i++){
            std::cout << "|";
            for(int j = 0; j < 9; j++){
                if((this->sudokuGrid)->getValueInGrid(k * 3 + i, j) != 0){
                    std::cout << (this->sudokuGrid)->getValueInGrid(k * 3 + i, j);
                }else{
                    std::cout << ".";
                }
                if(j%3 == 2){
                    std::cout << "|";
                }else{
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "+-----+-----+-----+" << std::endl;
    }

}

//This function prints the sudoku solution grid
void Sudoku::printSolution(){
    std::cout << "+-----+-----+-----+" << std::endl;
    for(int k = 0; k < 3; k++){
        for(int i = 0; i < 3; i++){
            std::cout << "|";
            for(int j = 0; j < 9; j++){
                if((this->completeGrid)->getValueInGrid(k * 3 + i, j) != 0){
                    std::cout << (this->completeGrid)->getValueInGrid(k * 3 + i, j);
                }else{
                    std::cout << ".";
                }
                if(j%3 == 2){
                    std::cout << "|";
                }else{
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "+-----+-----+-----+" << std::endl;
    }
}

//This function saves the data in an int array for sending the sudoku information to an other processor with MPI.
void Sudoku::exportMPI(int * data){
    for(int  i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            data[i*9 + j] = (int)(this->sudokuGrid->getValueInGrid(i, j));
            data[9*9 + i*9 + j] = (int)(this->completeGrid->getValueInGrid(i, j));
        }
    }
    data[2*9*9] = this->getDifficulty();
}

//This function loads the data received by an MPI message into the sudoku object.
void Sudoku::importMPI(int * data){
    for(int  i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            this->sudokuGrid->setValueInGrid(i, j, (short int)data[i*9 + j]);
            this->completeGrid->setValueInGrid(i, j, (short int)data[9*9 + i*9 + j]);
        }
    }
    this->difficulty = data[2*9*9];
}