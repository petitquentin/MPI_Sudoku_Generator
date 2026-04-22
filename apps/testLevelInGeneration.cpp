/* #include <string>
#include <string.h>
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
#include <cstdlib>
#include <stdlib.h>
#include <list>
#include <algorithm> */

#include <grid/grid.hpp>
#include <sudoku/sudoku.hpp>

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

bool compareSudoku(Sudoku* a, Sudoku* b) { return (a->getDifficulty() < b->getDifficulty()); }

void printHelp(const char* programName) {
    std::cout << "Usage: " << programName << " [options]" << std::endl;
    std::cout << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h, --help           Print this help message and exit" << std::endl;
    std::cout << "  -R <rounds>          Number of generation rounds (default: 100)" << std::endl;
}

int main(int argc, char** argv){
    //get parameters

    srand(time(0));
    int round = 100;
    for(int i = 1; i < argc; i++){
        if(strcasecmp(argv[i], "-h") == 0 || strcasecmp(argv[i], "--help") == 0){
            printHelp(argv[0]);
            return 0;
        }
        if(strcasecmp(argv[i], "-R") == 0 && (i + 1) < argc){
            round = (atoi(argv[i+1]));
        }
    } 
    
    //Define variables for the timer
    auto begin = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    double cpu_time_used;
    
    //start the timer
    begin = std::chrono::high_resolution_clock::now();

    std::time_t result = std::time(nullptr);
    std::cout << "Generation begin at " << std::asctime(std::localtime(&result)) << std::endl;
    std::vector<Sudoku*> vector;

    std::vector<int> levelsCount(6);
    std::vector<int> expectedLevel(6);

    for(int x = 0; x < 6; ++x){
        levelsCount[x] = 0;
        expectedLevel[x] = 0;
        if(x == 5){
            expectedLevel[x] = 600;
        }
    }
    int expectedGrid = 0;
    for(int x = 0; x < 6; ++x){
        expectedGrid += expectedLevel[x];
    }

    while(expectedGrid > 0){
        vector.push_back(new Sudoku());
        int i = vector.size() - 1;
        std::cout << i << std::endl;
        vector[i]->generatePuzzle();
        vector[i]->calculateDifficulty();
        vector[i]->calculateLevel();
        int newLevel = vector[i]->getLevel();
        while(newLevel > 0 && expectedLevel[newLevel-1] == 0){
            newLevel--;
        }
        std::cout << "newLevel" << newLevel << std::endl;
        if(newLevel > 0 && vector[i]->changeSudokuLevel(newLevel)){
            expectedLevel[newLevel-1]--;
        }else{
            
            vector.pop_back();
        }
        //vector[i]->changeSudokuLevel(1);
        expectedGrid = 0;
        for(int x = 0; x < 6; ++x){
            expectedGrid += expectedLevel[x];
        }
    }

    for(int i = 0; i < vector.size(); i++){
        levelsCount[vector[i]->getLevel()-1]++;
    }




    

    //stop the timer
    end = std::chrono::high_resolution_clock::now();
    //Calculate the difference between end and begin
    cpu_time_used = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();

    std::cout << "Sudoku generate in " << cpu_time_used/1000000000 << "seconds" << std::endl;


    for(int i = 0; i < 6; i++){
        std::cout << "levelsCount[" << i << "] : " << levelsCount[i] << std::endl;
    }
    


    return 0;
}