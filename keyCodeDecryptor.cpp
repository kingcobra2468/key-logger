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



int main(int argc, char ** argv){
    readFile * t = new readFile;
    conversion * f = new conversion;
    t->readingFromFile();
    f->iterKeys(t);
    
    return 0;
}
