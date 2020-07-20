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

double getTimeOfDay(){
    struct timeval tmp_time;
    gettimeofday(&tmp_time, NULL);
    return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}

int main(int argc, char** argv){

    srand(time(0));
    //get parameters
    /* int roundMax = 9999;
    int IDartist = -1;
    int wantInfos = 0;
    for(int i = 0; i < argc; i++){
        if(strcasecmp(argv[i], "-ID") == 0){
            IDartist = (atoi(argv[i+1]));
        }
        if(strcasecmp(argv[i], "-R") == 0){
            roundMax = (atoi(argv[i+1]));
        }
        if(strcasecmp(argv[i], "-I") == 0 || strcasecmp(argv[i], "-INFO") == 0){
            wantInfos = 1;
        }
    } */
    
    //Define variables for the timer
    auto begin = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    double cpu_time_used;
    
    //start the timer
    begin = std::chrono::high_resolution_clock::now();
    
    Sudoku sudoku;
    sudoku.generatePuzzle();
    sudoku.calculateDifficulty();

    

    //stop the timer
    end = std::chrono::high_resolution_clock::now();
    //Calculate the difference between end and begin
    cpu_time_used = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();

    std::cout << "Sudoku generate in " << cpu_time_used/1000000000 << "seconds" << std::endl;
    std::cout << "Difficulty score : " << sudoku.getDifficulty() << std::endl;
    std::cout << std::endl;
    sudoku.printSudoku();
    sudoku.printSolution();


    return 0;
}