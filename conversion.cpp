#include <fstream>
#include "stdio.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <ctime>
#include <list>
#include <utility>
#include "conversion.h"
#include "readFile.h"
#include "/home/erik/Documents/Programming/CPP/Library/myFunction.h"

char conversion::convertToChar(int character, bool shiftOn, bool capLock){
        if(!shiftOn && !capLock){
            return keyCodeToKeyKap[character];
    }
}

void conversion::iterKeys(readFile * object){
    std::ofstream outputFile("output.txt");
    struct specialKeys{
        bool previouskeyShift;
        bool capsOn;
    };
    std::string tempWord;
    tempWord.clear();
    specialKeys * keys = new specialKeys;
    std::list<std::pair<int, int>> * t = filteredData(object);
    std::cout << t->size();
    for(std::list<std::pair<int, int>>::iterator iterter = t->begin(); iterter != t->end(); ++iterter){
        if(iterter->first == 1){
            switch(iterter->second){
                case 42:
                    keys->previouskeyShift=true;
                    break;
                case 57:
                    outputFile << tempWord << std::endl;
                    tempWord.clear();
                    break;
                case 58:
                    keys->capsOn = keys->capsOn == true ? false : true;
                    break;
                case 14:
                    tempWord.pop_back();
                    break;
                case 28:
                    outputFile << tempWord << std::endl;
                    tempWord.clear();
                    break;
                default:
                    keys->previouskeyShift = false;
                    tempWord.push_back(convertToChar(iterter->second, keys->previouskeyShift, keys->capsOn));
                    std::cout << convertToChar(iterter->second, keys->previouskeyShift, keys->capsOn);
                    break;
            }
        }
    }
    outputFile.close();
}


std::list<std::pair<int, int>> * filteredData(readFile * object){
    return object->characters; 
}