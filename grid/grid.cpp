
#include <grid/grid.hpp>
#include <algorithm>
#include <iostream>

//Constructeur d'une grille de sudoku
Grid::Grid(){
    //Fill in the array of value
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            this->shuffleValue[j][i] = i+1;
        }
    }

    //Sort randomly the array
    //srand(time(0));
    for(int j = 0; j < 9; j++){
        std::random_shuffle(this->shuffleValue[j], (this->shuffleValue[j]) + 9);
    }
    //Set all value of the grid to EMPTYVALUE
    this->resetGrid();
}

//Destructor d'une grille de sudoku
Grid::~Grid(){

}

void Grid::setValueInGrid(int row, int col, short int value){
    this->grid[row][col] = value;
}


short int Grid::getValueInGrid(int row, int col){
    return this->grid[row][col];
}

//This function returns true if the grid is complete and returns false if there are elements that are not yet assigned.
//If it finds an unassigned element, the coordinates of the unassigned value found will be returned in the variables row and col
bool Grid::isComplete(int * row, int * col){
    for((*row) = 0; (*row) < 9; (*row) ++){
        for((*col) = 0; (*col) < 9; (*col) ++){
            if(this->grid[*row][*col] == EMPTYVALUE){
                return false;
            }
        }
    }
    return true;
}

//Function that returns true if number is already in the row and false if not.
bool Grid::isFindInRow(int row, short int number){
    for(int i = 0; i < 9; i ++){
        if(grid[row][i] == number)
            return true;
    }
    return false;
}

//Function that returns true if number is already in the col column and false if not.
bool Grid::isFindInCol(int col, short int number){
    for(int i = 0; i < 9; i ++){
        if(grid[i][col] == number)
            return true;
    }
    return false;
}

//Function that returns true if number is already in the block and false if not. 
//The block depends on the position of the number which is in coordinates (row, col) 
bool Grid::isFindInBlock(int row, int col, short int number){
    int rowBegin = row - row%3;
    int colBegin = col - col%3;

    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            if(grid[rowBegin + i][colBegin + j] == number){
                return true;
            }
        }
    }
    return false;
};

//Function that will return true if the insertion of number in the case (row, col) of the grid does not contradict the sudoku rules.
bool Grid::canBeInsertHere(int row, int col, short int number){
    if(isFindInRow(row, number) || isFindInCol(col, number) || isFindInBlock(row, col, number)){
        return false;
    }else{
        return true;
    }
}

//Recursive function to solve the grid
bool Grid::solveGrid()
{
    int row;
    int col;

    if (this->isComplete(&row, &col))
       return true;

    for (int num = 0; num < 9; num++)
    {
        if (this->canBeInsertHere(row, col, this->shuffleValue[row][num]))
        {
            this->grid[row][col] = this->shuffleValue[row][num];

            if (solveGrid())
                return true;

            this->grid[row][col] = EMPTYVALUE;
        }
    }

    return false;

}

//This function sets all the values of the grid and the complete grid to EMPTYVALUE value
void Grid::resetGrid(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            this->grid[i][j] = EMPTYVALUE;
        }
    }
}


//This function fill in the grid to have a grid which grid does not contradict the sudoku game rules
void Grid::initializeValideGrid(){
    this->solveGrid();
}

void Grid::copyGrid(Grid * otherGrid){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            otherGrid->setValueInGrid(i, j, this->grid[i][j]);
        }
    }
}

//Recursive function which check if the grid can be solved uniquely in one way
void Grid::isUniqueSolution(int * number){
    int row;
    int col;

    if(this->isComplete(&row, &col)){
        (*number)++;
    }else{
        for(int i = 0; i < 9; i++){
            if(canBeInsertHere(row, col, this->shuffleValue[row][i])){
                this->grid[row][col] = this->shuffleValue[row][i];
                this->isUniqueSolution(number);
            }
            this->grid[row][col] = EMPTYVALUE;
            if(*number >= 2){
                return;
            }
        }
    }
}

//This function will generate the puzzle, it will remove values from the sudoku grid and check that the sudoku still has only one solution
void Grid::generatePuzzle(){

    short int shufflePosition[81];

    for(int i = 0; i < 9*9; i++){
        shufflePosition[i] = i;
    }
    //srand(time(0));
    std::random_shuffle(shufflePosition, (shufflePosition) + 9*9);
    
    for(int i = 0; i < 9*9; i++){
        int row = (shufflePosition[i])/9;
        int col = (shufflePosition[i])%9;

        short int lastValue = this->grid[row][col];

        this->grid[row][col] = EMPTYVALUE;

        int number = 0;
        isUniqueSolution(&number);
        if(number != 1){
            this->grid[row][col] = lastValue;
        }
    }
}

//This function returns the number of empty element in the grid
int Grid::getNumberEmptyElement(){
    int numberEmptyElement = 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(this->grid[i][j] == EMPTYVALUE){
                numberEmptyElement++;
            }
        }
    }
    return numberEmptyElement;
}

//int Grid::getSpecificEmptyValue(){}

//This function returns the ind'th value of the shuffleValue array
short int Grid::getShuffleValue(int i,int ind){
    return shuffleValue[i][ind];
}