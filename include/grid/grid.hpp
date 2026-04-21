#ifndef GRID_HPP
#define GRID_HPP

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

#include <algorithm>

#define EMPTYVALUE 0

class Grid
{
    public:
        // Create a grid with randomized candidate order and all cells set to EMPTYVALUE.
        Grid(void);
        ~Grid(void);

        // Basic cell accessors.
        void setValueInGrid(int row, int col, short int value);
        short int getValueInGrid(int row, int col);

        // Backtracking helpers and solver.
        bool isComplete(int * row, int * col);
        bool solveGrid();

        // Reset/fill/copy utilities.
        void resetGrid();
        void initializeValideGrid();
        void copyGrid(Grid * otherGrid);

        // Remove clues while preserving one unique solution.
        void generatePuzzle();

        // Access shuffled candidate values and board statistics.
        short int getShuffleValue(int i, int ind);
        int getNumberEmptyElement();

        // Return true when a number can be inserted at (row, col).
        bool canBeInsertHere(int row, int col, short int number);

    protected:
        bool isFindInRow(int row, short int number);
        bool isFindInCol(int col, short int number);
        bool isFindInBlock(int row, int col, short int number);
        void isUniqueSolution(int * number = 0);

    private:
        short int grid[9][9];
        short int shuffleValue[9][9];


};
#endif