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
        LatexGenerator(void); // Build a generator with default output path.
        LatexGenerator(std::string p); // Build a generator with a custom output path.
        ~LatexGenerator(void); // Close resources used by the generator.
        void startDocument(int nbPuzzle); // Write LaTeX header and start puzzle section.
        void addSudokuPuzzle(Sudoku * s); // Append one Sudoku puzzle to the document.
        void generatePuzzleToSolution(); // Switch document from puzzle pages to solution pages.
        void addSolution(Sudoku * s); // Append one Sudoku solution to the document.
        void endDocument(); // Finalize and close the LaTeX document.
        int getNbPuzzleAdded(); // Return how many puzzles were written.
        int getNbSolutionAdded(); // Return how many solutions were written.
        int getNbPuzzleExpected(); // Return how many puzzles are expected in total.


        
    protected:
        bool getIsStarted(); // Tell whether document generation has started.
        bool getIsEnded(); // Tell whether document generation is finished.
        bool getIsAtSolution(); // Tell whether writer is currently in solution section.
        

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