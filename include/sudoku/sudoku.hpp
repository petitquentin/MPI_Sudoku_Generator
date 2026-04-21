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
        // Build an empty Sudoku object containing one puzzle grid and one solution grid.
        Sudoku();
        ~Sudoku();

        // Compute a difficulty score for the current puzzle using candidate analysis.
        void calculateDifficulty();

        // Return the last computed difficulty score.
        int getDifficulty();

        // Generate a new puzzle and its corresponding complete solution.
        void generatePuzzle();

        // Access the playable puzzle grid (contains EMPTYVALUE for hidden cells).
        Grid * getSudokuGrid();

        // Access the full solved grid.
        Grid * getCompleteGrid();

        // Print puzzle and solution to stdout in a human-readable board format.
        void printSudoku();
        void printSolution();

        // Pack/unpack one Sudoku in a fixed int buffer for MPI communication.
        void exportMPI(int * data);
        void importMPI(int * data);

        // Convert between level index and expected number of empty cells.
        int associateLevel(int level);
        int associateNbEmpty(int nbEmpty);

        // Try to adjust the current puzzle to a target level.
        bool changeLevel(int levelExpected);

        // Return computed level, max reachable level and current empty count.
        int getLevel();
        int maxLevelPossible();
        int getNumberEmptyElement();

        // Return puzzle cells as an 81-character numeric string.
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