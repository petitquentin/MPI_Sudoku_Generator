#ifndef SUDOKU_HPP
#define SUDOKU_HPP

//#include <curl/curl.h>
//#include <json/json.h>
#include <string>
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
#include<sstream>

#include <grid/grid.hpp>

#define VERYEASY 41
#define EASY 46
#define MEDIUM 51
#define HARD 56
#define EXTREME 58


class Sudoku
{
    public:
        Sudoku();
        ~Sudoku();
        void calculateDifficulty();
        int getDifficulty();
        void generatePuzzle();
        Grid * getSudokuGrid();
        Grid * getCompleteGrid();
        void printSudoku();
        void printSolution();
        void exportMPI(int * data);
        void importMPI(int * data);

        int associateLevel(int level);
        int associateNbEmpty(int nbEmpty);
        bool changeLevel(int levelExpected);
        int getLevel();
        int maxLevelPossible();
        int getNumberEmptyElement();
        std::string getStringSudoku();
        
        // overload the operator<
        bool operator<(const Sudoku& r) const
        {
            return difficulty < r.difficulty;
        }

        // overload the operator>
        bool operator>(const Sudoku& r) const
        {
            return difficulty > r.difficulty;
        }
    protected:

    private:
        Grid * sudokuGrid;
        Grid * completeGrid;
        int level;
        int difficulty;


};

bool compareSudoku(Sudoku* a, Sudoku* b);

#endif