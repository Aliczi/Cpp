#pragma once
#include <iostream>
#include <string>

using namespace std;

class Logger{
    bool out;
    public:
    Logger();
    Logger(bool);
    void log(string);
    
};