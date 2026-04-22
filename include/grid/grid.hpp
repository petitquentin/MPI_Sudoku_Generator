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
        Grid(void); // Build an empty 9x9 grid.
        ~Grid(void); // Destroy the grid instance.
        void setValueInGrid(int row, int col, short int value); // Set a value at the given row/column.
        short int getValueInGrid(int row, int col); // Read the value at the given row/column.
        bool isComplete(int * row, int * col); // Check if grid is complete; return first empty cell if not.
        bool solveGrid(); // Solve the current grid using backtracking.
        void resetGrid(); // Clear the grid to its initial empty state.
        void initializeValideGrid(); // Create a fully valid solved grid.
        void copyGrid(Grid * otherGrid); // Copy values from another grid.
        void generatePuzzle(); // Remove values from solved grid to create a puzzle.
        short int getShuffleValue(int ind); // Get shuffled candidate value at index.
        int getNumberEmptyElement(); // Count how many cells are empty.
        bool canBeInsertHere(int row, int col, short int number); // Validate whether a number fits at position.

    protected:
        bool isFindInRow(int row, short int number); // Check whether number already exists in row.
        bool isFindInCol(int col, short int number); // Check whether number already exists in column.
        bool isFindInBlock(int row, int col, short int number); // Check whether number exists in 3x3 block.
        void isUniqueSolution(int * number = 0); // Count/verify number of solutions for current puzzle.

    private:
        short int grid[9][9];
        short int shuffleValue[9];


};
#endif