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

void printHelp(const char* programName) {
    std::cout << "Usage: mpirun -n <processes> " << programName << " [options]" << std::endl;
    std::cout << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h, --help           Print this help message and exit" << std::endl;
    std::cout << "  -nb <n>              Number of documents for each level (default: 100)" << std::endl;
    std::cout << "  -nb1 <n>             Number of level 1 documents" << std::endl;
    std::cout << "  -nb2 <n>             Number of level 2 documents" << std::endl;
    std::cout << "  -nb3 <n>             Number of level 3 documents" << std::endl;
    std::cout << "  -nb4 <n>             Number of level 4 documents" << std::endl;
    std::cout << "  -nb5 <n>             Number of level 5 documents" << std::endl;
    std::cout << "  -nb6 <n>             Number of level 6 documents" << std::endl;
    std::cout << "  -G <n>               Number of sudoku grids per document (default: 100)" << std::endl;
    std::cout << "  -g <n>               Same as -G" << std::endl;
    std::cout << "  -P <path>            Output path (default: output)" << std::endl;
    std::cout << "  -PATH <path>         Same as -P" << std::endl;
}

int main(int argc, char** argv){
    int my_rank, p;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    srand(time(0) * (my_rank+2));

    std::vector<int> numberDocuments(6);
    for(int i = 0; i < 6; i++){
        numberDocuments[i] = 0;
    }
    int nbDocumentsAll = 0;
    int gridByDocument = 100;
    std::string path = "output";
    for(int i = 1; i < argc; i++){
        if(strcasecmp(argv[i], "-h") == 0 || strcasecmp(argv[i], "--help") == 0){
            if(my_rank == 0){
                printHelp(argv[0]);
            }
            MPI_Finalize();
            return 0;
        }
        if((strcasecmp(argv[i], "-nb") == 0 || strcasecmp(argv[i], "-NB") == 0) && (i + 1) < argc){
            nbDocumentsAll = (atoi(argv[i+1]));
        }
        if((strcasecmp(argv[i], "-nb1") == 0 || strcasecmp(argv[i], "-NB1") == 0) && (i + 1) < argc){
            numberDocuments[0] = (atoi(argv[i+1]));
        }
        if((strcasecmp(argv[i], "-nb2") == 0 || strcasecmp(argv[i], "-NB2") == 0) && (i + 1) < argc){
            numberDocuments[1] = (atoi(argv[i+1]));
        }
        if((strcasecmp(argv[i], "-nb3") == 0 || strcasecmp(argv[i], "-NB3") == 0) && (i + 1) < argc){
            numberDocuments[2] = (atoi(argv[i+1]));
        }
        if((strcasecmp(argv[i], "-nb4") == 0 || strcasecmp(argv[i], "-NB4") == 0) && (i + 1) < argc){
            numberDocuments[3] = (atoi(argv[i+1]));
        }
        if((strcasecmp(argv[i], "-nb5") == 0 || strcasecmp(argv[i], "-NB5") == 0) && (i + 1) < argc){
            numberDocuments[4] = (atoi(argv[i+1]));
        }
        if((strcasecmp(argv[i], "-nb6") == 0 || strcasecmp(argv[i], "-NB6") == 0) && (i + 1) < argc){
            numberDocuments[5] = (atoi(argv[i+1]));
        }
        if((strcasecmp(argv[i], "-G") == 0 || strcasecmp(argv[i], "-g") == 0) && (i + 1) < argc){
            gridByDocument = (atoi(argv[i+1]));
        }
        if((strcasecmp(argv[i], "-PATH") == 0 || strcasecmp(argv[i], "-P") == 0) && (i + 1) < argc){
            path = argv[i+1];
        }
    } 
    int sum = 0;
    for(int i = 0; i < 6; i++){
        sum += numberDocuments[i];
    }
    if(sum == 0){
        if(nbDocumentsAll == 0){
            nbDocumentsAll = 100;
        }
        for(int i = 0; i < 6; i++){
            numberDocuments[i] = nbDocumentsAll;
        }
    }
    std::vector<int> gridToDo(6);
    for(int i = 0; i < 6; i++){
        gridToDo[i] = floor((numberDocuments[i]*gridByDocument*1.0)/p);
        if((numberDocuments[i]*gridByDocument)%p < my_rank){
            gridToDo[i]++;
        }
    }
    std::vector<Sudoku*> vector;

    int expectedGrid = 0;
    for(int x = 0; x < 6; x++){
        expectedGrid += gridToDo[x];
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

    if(my_rank != 0){
        int nbAllGrid = 0;
        for(int i = 0; i < 6; i++){
            nbAllGrid += numberDocuments[i]*gridByDocument;
        }
        std::vector<std::vector<Sudoku*>> allSudoku;
        for(int i = 0; i < 6; i++){
            std::vector<Sudoku *> vec;
            allSudoku.push_back(vec);
        }
        for(int i = 0; i < vector.size(); i++){
            allSudoku[vector[i]->getLevel()-1].push_back(vector[i]);
            nbAllGrid--;
        }
        int * bufferRecv;
        bufferRecv = (int *)malloc(sizeof(int) * ((2 * 9 * 9) + 1));
        while(nbAllGrid > 0){
            MPI_Recv(bufferRecv, (2 * 9 * 9) + 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
            vector.push_back(new Sudoku());
        }

    }else{

    }


    //get parameters
    
     
    
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
    std::cout << "a" << std::endl;


    LatexGenerator latexGen;
    std::cout << "b" << std::endl;
    latexGen.startDocument(vector.size());
    std::cout << "c" << std::endl;
    for(int i = 0; i < vector.size(); i++){
        latexGen.addSudokuPuzzle(vector[i]);
    }
    std::cout << "d" << std::endl;
    latexGen.generatePuzzleToSolution();
    std::cout << "e" << std::endl;
    for(int i = 0; i < vector.size(); i++){
        latexGen.addSolution(vector[i]);
    }
    std::cout << "f" << std::endl;
    latexGen.endDocument(); 
    std::cout << "g" << std::endl;

    //stop the timer
    end = std::chrono::high_resolution_clock::now();
    //Calculate the difference between end and begin
    cpu_time_used = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();

    std::cout << "Sudoku generate in " << cpu_time_used/1000000000 << "seconds" << std::endl;
    std::cout << std::endl;


    return 0;
}