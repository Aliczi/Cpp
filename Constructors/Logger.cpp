#include <iostream>
#include "Logger.h"
#include <ctime>
#include <string.h>


using namespace std;

Logger::Logger(bool o=true){
    out=o;
}

Logger::Logger(){ out = true; }

void Logger::log(string s){
    time_t now = time(0);
    char* dt = strtok(ctime (&now), "\n");
    
    if (out) std::cout<<dt<<"\t"<< s<<endl;
}