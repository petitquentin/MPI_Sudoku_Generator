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

int main(int argc, char** argv){
    //get parameters

    srand(time(0));
    int round = 100;
    for(int i = 0; i < argc; i++){
        if(strcasecmp(argv[i], "-R") == 0){
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


    for(int i = 0; i < round; i ++){
        std::cout << i << std::endl;
        vector.push_back(new Sudoku());
        vector[i]->generatePuzzle();
        vector[i]->calculateDifficulty();
    }

    std::sort(vector.begin(), vector.end(), compareSudoku);

    

    //stop the timer
    end = std::chrono::high_resolution_clock::now();
    //Calculate the difference between end and begin
    cpu_time_used = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();

    std::cout << "Sudoku generate in " << cpu_time_used/1000000000 << "seconds" << std::endl;


    for(int i = 0; i < vector.size(); i++){
        std::cout << "vector[" << i << "] score : " << vector[i]->getDifficulty() << std::endl;
    }
    


    return 0;
}