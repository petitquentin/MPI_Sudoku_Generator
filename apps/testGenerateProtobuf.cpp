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
#include <sudoku/sudoku.pb.h>

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
#include <filesystem>

double getTimeOfDay(){
    struct timeval tmp_time;
    gettimeofday(&tmp_time, NULL);
    return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}
bool compareSudoku(Sudoku* a, Sudoku* b) { 
    return (a->getDifficulty() < b->getDifficulty());
}

bool notFinish(std::vector<std::vector<Sudoku*>> elem, int nbSudoku){
    for(int i =1; i < 6; i++){
        if(elem[i].size() < nbSudoku){
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv){
    srand(time(0));
    //get parameters
    int round = 100;
    std::string path = "output";
    for(int i = 0; i < argc; i++){
        if(strcasecmp(argv[i], "-R") == 0){
            round = (atoi(argv[i+1]));
        }
        if(strcasecmp(argv[i], "-PATH") == 0 || strcasecmp(argv[i], "-P") == 0){
            path = argv[i+1];
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

    std::vector<std::vector<Sudoku*>> vector;

    for(int i = 0; i < 6; i++){
        std::vector<Sudoku*> vectorSudoku;
        vector.push_back(vectorSudoku);
    }

    std::cout << "PARAMS : " << std::endl;
    std::cout << " Number of round : " << round << std::endl;
    std::cout << " Path  : " << path << std::endl;
    std::cout << std::endl;

    int totalSudoku = 0;

    /* std::vector<int> nbForLevel;
    for(int i = 0; i < 6; i++){
        nbForLevel.push_back(0);
    } */
    while(notFinish(vector, round)){
        Sudoku * newSudoku = new Sudoku();
        totalSudoku ++;
        if(totalSudoku % 10 == 0){
            for(int i = 1; i < 6 ; i++){
                std::cout << vector[i].size() << " ";

            }
            std::cout << std::endl;
        }
        newSudoku->generatePuzzle();
        int newLevel = newSudoku->maxLevelPossible();
        std::cout << newLevel << std::endl;
        while(newLevel > 0 && vector[newLevel].size() >= round){
            newLevel--;
        }
        if(newLevel > 0){
            newSudoku->changeLevel(newLevel);
            newSudoku->calculateDifficulty();
            vector[newLevel].push_back(newSudoku);
        }else{
            delete newSudoku;
        }
    }

    for(int i = 1; i < vector.size(); i ++){
        for(int j = 0; j < vector[i].size(); j++){
            std::cout << i << " : " << vector[i][j]->getStringSudoku() << " (" << vector[i][j]->getNumberEmptyElement() << ")" << std::endl;
        }
    }

    //Save protobuf
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < vector[i].size(); j++){

            sudoku::Sudoku * actualSudoku = new sudoku::Sudoku;
            actualSudoku->set_nbempty(vector[i][j]->getNumberEmptyElement());
            actualSudoku->set_score(vector[i][j]->getDifficulty());
            actualSudoku->set_level(vector[i][j]->getLevel());
            for(int is = 0; is < 9; is++){
                for( int js = 0; js < 9; js++){
                    actualSudoku->add_values(vector[i][j]->getSudokuGrid()->getValueInGrid(i, j));
                }
            }
            std::string actualPath = path;
            actualPath += "/" + std::to_string(vector[i][j]->getLevel());

            int status;
            std::string command = "mkdir ";
            command += actualPath;
            status = system(command.c_str()); // Creating a directory
            if (status != -1)
                std::cout << "Directories are created" << std::endl;
            /* std::filesystem::current_path(std::filesystem::temp_directory_path());
            std::filesystem::create_directories(actualPath);
            std::filesystem::permissions(actualPath, std::filesystem::perms::others_all, std::filesystem::perm_options::remove); */
            actualPath += "/" + vector[i][j]->getStringSudoku();

            std::fstream ostream(actualPath, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
            
            if(!actualSudoku->SerializeToOstream(&ostream)){
                std::cout << "Failed to write the sudoku " << i << " " << j << std::endl;
            }
            std::cout << "Path : " << actualPath << std::endl;
            ostream.close();
            
        }
    }


    /* for(int i = 0; i < vector.size(); i ++){
        std::cout << i << std::endl;
        vector.push_back(new Sudoku());
        vector[i]->generatePuzzle();
        if(vector[i]->changeLevel(vector[i]->maxLevelPossible())){
            std::cout << "Round " << i << " : Successful level change" << std::endl;
        }
        vector[i]->calculateDifficulty();
    } */


    std::cout << "RESULT : " << std::endl;
    std::cout << "Total sudoku generated : " << totalSudoku << std::endl;
    for(int i = 1; i < 6; i++){
        std::cout << "Sudoku with level "<< i << " : " << vector[i].size() << std::endl; 
    }

    //stop the timer
    end = std::chrono::high_resolution_clock::now();
    //Calculate the difference between end and begin
    cpu_time_used = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();

    std::cout << "Sudoku generate in " << cpu_time_used/1000000000 << "seconds" << std::endl;
    std::cout << std::endl;


    return 0;
}