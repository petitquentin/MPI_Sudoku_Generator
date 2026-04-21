# MPI_Sudoku_Generator

This program is a Sudoku generator in distributed computing. It is used to generate playable Sudoku puzzles and solutions. An additional feature allows to create a PDF document with LaTeX to easily print the generated puzzles. 

## Project overview

The codebase is organized in small modules with clear responsibilities:

1. `grid/`: low-level Sudoku grid logic (solve, uniqueness checks, puzzle carving).
2. `sudoku/`: high-level Sudoku object wrapping one puzzle grid and one complete solution grid.
3. `latexGenerator/`: LaTeX document writer for puzzle books and solution pages.
4. `proto/`: protobuf representation for Sudoku data exchange.
5. `apps/`: small test/demo executables for each feature.

Typical generation pipeline:

1. Build a valid solved grid (`Grid::initializeValideGrid`).
2. Copy it as the complete solution.
3. Remove values while keeping a unique solution (`Grid::generatePuzzle`).
4. Estimate difficulty (`Sudoku::calculateDifficulty`).
5. Optionally send puzzles through MPI (`Sudoku::exportMPI` / `Sudoku::importMPI`).
6. Optionally export a printable PDF through LaTeX.

## Examples

### Sudoku puzzle
* ![](doc/example/example_puzzle.png)

### PDF Output 
* [Example output file](doc/example/output_example.pdf)

## Prerequisites

To run the generator, you need to install the following items on your device :

1. C++ Compiler with **c++11** support.
2. Cmake (Minimum required version 3.7).
3. MPI implementation (like [MPICH](https://www.mpich.org/downloads/))
4. `PdfLatex` 
    * The following package is recommended: `texlive-full`. This package will include all the LaTeX packages that will be used to generate the PDF document. 
    * If `texlive-full` is so large install the packages `texlive-fonts-recommended` and `texlive-latex-recommended`.

## Installation

Clone the project in a target directory :

```
git clone https://github.com/petitquentin/MPI_Sudoku_Generator.git
```

Deploy with CMake :

```
cd MPI_Sudoku_Generator
mkdir build
cd build
cmake .. 
```

Install :

```
make
```

Run an example test executable from the build directory:

```
./apps/testGenerateSudoku
```

Run MPI send/receive test (2 or more ranks required):

```
mpirun -n 4 ./apps/testMPISendReceive
```

Now, the project have been installed in the `<TargetDirectory>/MPI_Sudoku_Generator/build/` folder.

## Useful test apps

1. `testGenerateSudoku`: generates one puzzle, computes difficulty, prints puzzle and solution.
2. `testMPISendReceive`: rank 1 generates and sends two Sudokus to rank 0 through MPI.
3. `testLatexGenerator`: creates a LaTeX output file from generated puzzles.
4. `testGenerateProtobuf`: serializes/deserializes Sudoku data with protobuf.

## Ressources
    * [CMake Official Website](https://cmake.org/)
    * [Difficulty estimation used](https://dlbeer.co.nz/articles/sudoku.html)