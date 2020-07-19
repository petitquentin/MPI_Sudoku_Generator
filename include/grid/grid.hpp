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
        Grid(void);
        ~Grid(void);
        void setValueInGrid(int row, int col, short int value);
        short int getValueInGrid(int row, int col);
        bool isComplete(int * row, int * col);
        bool solveGrid();
        void resetGrid();
        void initializeValideGrid();
        void copyGrid(Grid * otherGrid);
        void generatePuzzle();
        short int getShuffleValue(int ind);
        int getNumberEmptyElement();
        bool canBeInsertHere(int row, int col, short int number);

    protected:
        bool isFindInRow(int row, short int number);
        bool isFindInCol(int col, short int number);
        bool isFindInBlock(int row, int col, short int number);
        void isUniqueSolution(int * number = 0);

    private:
        short int grid[9][9];
        short int shuffleValue[9];


};
#endif