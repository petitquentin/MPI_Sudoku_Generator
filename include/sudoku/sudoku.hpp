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

#include <grid/grid.hpp>

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

    protected:

    private:
        Grid * sudokuGrid;
        Grid * completeGrid;
        int level;
        int difficulty;


};
#endif