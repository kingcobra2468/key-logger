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
#ifndef CONVERSION_H
#define CONVERSION_H

class conversion{
    private:
        std::map<int, char> keyCodeToKeyKap = {   
            {2, '1'},
            {3, '2'},
            {4, '3'},
            {5, '4'},
            {6, '5'},
            {7, '6'},
            {8, '7'},
            {9, '8'},
            {10, '9'},
            {11, '0'},
            {12, '-'},
            {13, '='},
            {16, 'q'},
            {17, 'w'},
            {18, 'e'},
            {19, 'r'},
            {20, 't'},
            {21, 'y'},
            {22, 'u'},
            {23, 'i'},
            {24, 'o'},
            {25, 'p'},
            {26, '['},
            {27, ']'},
            {28, '3'},
            {30, 'a'},
            {31, 's'},
            {32, 'd'},
            {33, 'f'},
            {34, 'g'},
            {35, 'h'},
            {36, 'j'},
            {37, 'k'},
            {38, 'l'},
            {39, ';'},
            {40, '\''},
            {41, '`'},
            {43, '\\'},
            {44, 'z'},
            {45, 'x'},
            {46, 'c'},
            {47, 'v'},
            {48, 'b'},
            {49, 'n'},
            {50, 'm'},
            {51, ','},
            {52, '.'},
            {53, '/'}};
    public:
        char convertToChar(int character, bool shiftOn, bool capLock);
        void iterKeys(readFile * object);
};

#endif
