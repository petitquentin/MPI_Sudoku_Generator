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
#include <mpi.h>

double getTimeOfDay(){
    struct timeval tmp_time;
    gettimeofday(&tmp_time, NULL);
    return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}

int main(int argc, char** argv){

    int my_rank, p;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    srand(time(0) * (my_rank+2));
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
    if(p < 2){
        std::cout << "You need to use more than 1 nodes to execute this test" << std::endl;
        return 0;
    }
    
    //Define variables for the timer
    auto begin = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    double cpu_time_used;
    
    //start the timer
    begin = std::chrono::high_resolution_clock::now();
    
    

    Sudoku sudoku;
    Sudoku sudoku2;
    if(my_rank == 1){
        sudoku.generatePuzzle();
        sudoku2.generatePuzzle();
        sudoku.calculateDifficulty();
        sudoku2.calculateDifficulty();
        std::cout << "Rank " << my_rank << " : Difficulty = " << sudoku.getDifficulty() << " and " << sudoku2.getDifficulty() << std::endl;
        int * bufferSend;
        bufferSend = (int *)malloc(sizeof(int) * 2 * ((2 * 9 * 9) + 1));
        sudoku.exportMPI(bufferSend);
        sudoku2.exportMPI(&(bufferSend[163]));
        MPI_Send(bufferSend, 2 * ((2 * 9 * 9) + 1), MPI_INT, 0, 0, MPI_COMM_WORLD);
        free(bufferSend);
    }
    if(my_rank == 0){
        int * bufferRecv;
        bufferRecv = (int *)malloc(sizeof(int) * 2 * ((2 * 9 * 9) + 1));
        MPI_Recv(bufferRecv, 2 * ((2 * 9 * 9) + 1), MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        sudoku.importMPI(bufferRecv);
        sudoku2.importMPI(&(bufferRecv[163]));
        std::cout << "Rank " << my_rank << " : Difficulty = " << sudoku.getDifficulty() << " and " << sudoku2.getDifficulty() << std::endl;
    }

    

    

    //stop the timer
    end = std::chrono::high_resolution_clock::now();
    //Calculate the difference between end and begin
    cpu_time_used = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();

    std::cout << "Sudoku generate in " << cpu_time_used/1000000000 << "seconds" << std::endl;
    std::cout << std::endl;


    return 0;
}