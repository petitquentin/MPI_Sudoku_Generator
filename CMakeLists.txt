cmake_minimum_required(VERSION 3.7...3.14)
project(SUDOKUGENERATOR VERSION 0.1 LANGUAGES CXX)

find_package(MPI)
if(MPI_FOUND)
    include_directories(${MPI_INCLUDE_PATH})
    message([NOTICE] "MPI was found")
endif(MPI_FOUND)

# Set MPICXX as the CXX compiler

SET(CMAKE_CXX_COMPILER mpicxx)

add_subdirectory(grid)
add_subdirectory(sudoku)
add_subdirectory(latexGenerator)
add_subdirectory(apps)

