#include <fstream>
#include "stdio.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <ctime>
#include <list>
#include <utility>
#include <new>
#ifndef READFILE_H
#define READFILE_H

class readFile{

    private:
        std::list<std::pair<int, int>> * characters = new std::list<std::pair<int, int>>;
        int * t = new int;
    public:
        void readingFromFile();
        friend std::list<std::pair<int, int>> * filteredData(readFile * object);
};

#endif