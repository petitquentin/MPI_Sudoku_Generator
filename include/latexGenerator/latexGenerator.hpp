#ifndef LATEXGENERATOR_HPP
#define LATEXGENERATOR_HPP

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <cmath>
#include <vector>
#include <memory>
#include <cstdint>
#include <sys/time.h>
#include <chrono>
#include <string>

#include <algorithm>

#include <grid/grid.hpp>
#include <sudoku/sudoku.hpp>

class LatexGenerator
{
    public:
        LatexGenerator(void);
        LatexGenerator(std::string p);
        ~LatexGenerator(void);
        void startDocument(int nbPuzzle);
        void addSudokuPuzzle(Sudoku * s);
        void generatePuzzleToSolution();
        void addSolution(Sudoku * s);
        void endDocument();
        int getNbPuzzleAdded();
        int getNbSolutionAdded();
        int getNbPuzzleExpected();


        
    protected:
        bool getIsStarted();
        bool getIsEnded();
        bool getIsAtSolution();
        

    private:
        std::ofstream ofs;
        std::string path;
        bool isStarted;
        bool isAtSolution;
        bool isEnded;
        int nbPuzzle;
        int nbPuzzleAdded;
        int nbSolutionAdded;
        int nbColumnBreak;


};
#endif