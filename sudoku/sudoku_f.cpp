
#include <sudoku/sudoku.hpp>
#include <grid/grid.hpp>

#include <vector>
#include <iostream>

bool compareSudoku(Sudoku* a, Sudoku* b){
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(a->getSudokuGrid()->getValueInGrid(i, j) != b->getSudokuGrid()->getValueInGrid(i, j)){
                return false;
            }
        }
    }
    return true;
}