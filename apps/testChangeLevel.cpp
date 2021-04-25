#include <grid/grid.hpp>
#include <sudoku/sudoku.hpp>
#include <latexGenerator/latexGenerator.hpp>

#include <chrono>
#include <mpi.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>

double getTimeOfDay(){
    struct timeval tmp_time;
    gettimeofday(&tmp_time, NULL);
    return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}
bool compareSudoku(Sudoku* a, Sudoku* b) { 
    return (a->getDifficulty() < b->getDifficulty());
}

int main(int argc, char** argv){
    srand(time(0));
    //get parameters
    int round = 100;
    std::string path = "output";
    int levelExpected = 1;
    for(int i = 0; i < argc; i++){
        if(strcasecmp(argv[i], "-R") == 0){
            round = (atoi(argv[i+1]));
        }
        if(strcasecmp(argv[i], "-L") == 0){
            levelExpected = (atoi(argv[i+1]));
        }
    } 

    std::cout << "PARAMS : " << std::endl;
    std::cout << " Number of round : " << round << std::endl;
    std::cout << " Expected Level  : " << round << std::endl;
     
    
    //Define variables for the timer
    auto begin = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    double cpu_time_used;
    
    //start the timer
    begin = std::chrono::high_resolution_clock::now();
    std::time_t result = std::time(nullptr);
    std::cout << "Generation begin at " << std::asctime(std::localtime(&result)) << std::endl;

    std::vector<Sudoku*> vector;
    std::cout << std::endl;


    for(int i = 0; i < round; i ++){
        std::cout << i << std::endl;
        vector.push_back(new Sudoku());
        vector[i]->generatePuzzle();
        if(vector[i]->changeLevel(levelExpected)){
            std::cout << "Round " << i << " : Successful level change" << std::endl;
        }
        vector[i]->calculateDifficulty();
    }

    std::sort(vector.begin(), vector.end(), compareSudoku);
    std::cout << "a" << std::endl;

    int nbLevelDiff = 0;
    int nbEmptySupp = 0;

    for(int i = 0; i < vector.size(); i ++){
        if(vector[i]->getLevel() != levelExpected){
            nbLevelDiff ++;
            if(vector[i]->getNumberEmptyElement() < vector[i]->associateLevel(levelExpected)){
                nbEmptySupp++;
            }
            
        }
        std::cout << i << " : " << vector[i]->getLevel() << " " << vector[i]->getNumberEmptyElement() <<"/" <<  vector[i]->associateLevel(levelExpected) << std::endl;
    }

    std::cout << "Sudoku without the same level : " << nbLevelDiff << std::endl;
    std::cout << "Sudoku impossible to change level : " << nbEmptySupp << std:: endl;

    //stop the timer
    end = std::chrono::high_resolution_clock::now();
    //Calculate the difference between end and begin
    cpu_time_used = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();

    std::cout << "Sudokus generate in " << cpu_time_used/1000000000 << "seconds" << std::endl;
    std::cout << std::endl;


    return 0;
}