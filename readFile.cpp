#include <fstream>
#include "stdio.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <ctime>
#include <list>
#include <utility>
#include "readFile.h"
#include <new>
#include "/home/erik/Documents/Programming/CPP/Library/myFunction.h"



void readFile::readingFromFile(){ //std::string fileName
    methods * process = new methods;
    time_t today = time(NULL);
    struct tm * todayDate = localtime(&today);
    std::ifstream * reading = new std::ifstream("." + std::to_string(todayDate->tm_mon) 
    + "." + std::to_string(todayDate->tm_mday) + "." 
    + std::to_string(todayDate->tm_year + 1900) + ".KeyLogger.txt");
    if (reading->is_open()){
        std::string input;
        while(!reading->eof()){
            getline(*reading, input);
            if(input.empty()){break;};
            characters->push_back(
                std::make_pair(
                    std::stoi(process->splitString(input)->front()),
                    std::stoi(process->splitString(input)->back())
                )
            );
        }
    }
    
    reading->close();
}
