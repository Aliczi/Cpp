#pragma once
#include <iostream>
#include <ctime>

using namespace std;


class Stopper{
    clock_t st;
    double duration;

    public:
    void start_counter();
    void stop_counter();
    void reset_counter();
    void get_count();

};