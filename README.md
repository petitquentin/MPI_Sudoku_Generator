# MPI_Sudoku_Generator

This program is a Sudoku generator in distributed computing. It is used to generate playable Sudoku puzzles and solutions. An additional feature allows to create a PDF document with LaTeX to easily print the generated puzzles. 

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

Now, the project have been installed in the `<TargetDirectory>/MPI_Sudoku_Generator/build/` folder.

## Ressources
    * [CMake Official Website](https://cmake.org/)
    * [Difficulty estimation used](https://dlbeer.co.nz/articles/sudoku.html)