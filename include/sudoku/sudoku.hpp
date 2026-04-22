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
#include <string>
#include <map>

#include <grid/grid.hpp>

class Sudoku
{
    public:
        Sudoku(); // Build an empty Sudoku object.
        Sudoku(std::string str); // Build a Sudoku from serialized input.
        ~Sudoku(); // Release owned grid resources.
        void calculateDifficulty(); // Compute puzzle difficulty score.
        int getDifficulty(); // Return current difficulty score.
        void generatePuzzle(); // Generate a new puzzle and its solution.
        void addNewValueInGrid(); // Add one value to help adjust puzzle state.
        Grid * getSudokuGrid(); // Access the playable puzzle grid.
        Grid * getCompleteGrid(); // Access the solved reference grid.
        void printSudoku(); // Print the puzzle grid to standard output.
        void printSolution(); // Print the solution grid to standard output.
        void exportMPI(int * data); // Serialize Sudoku data for MPI transfer.
        void importMPI(int * data); // Load Sudoku data received through MPI.
        void calculateLevel(); // Compute discrete level from difficulty.
        std::string getLevelString(); // Return level as human-readable string.
        int getLevel(); // Return numeric level.
        bool changeSudokuLevel(int expectedLevel); // Regenerate/adjust puzzle to target level.
        
        // overload the operator<
        bool operator<(const Sudoku& r) const // Compare by difficulty (ascending).
        {
            return difficulty < r.difficulty;
        }

        // overload the operator>
        bool operator>(const Sudoku& r) const // Compare by difficulty (descending).
        {
            return difficulty > r.difficulty;
        }
    protected:

    private:
        Grid * sudokuGrid;
        Grid * completeGrid;
        int level;
        int difficulty;
        std::map<int, std::string> mapLevel;
        void FillInTheMap(); // Initialize the level-to-label lookup map.



};
#endif