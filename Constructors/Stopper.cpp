#include <iostream>
#include "Stopper.h"
#include <time.h>

using namespace std;

void Stopper::start_counter(){
    st = clock();
}

void Stopper::stop_counter(){
    duration = ( clock() - st );
}

void Stopper::get_count(){
    cout<< "Time counted: " << duration << " miliseconds" << endl;
}

void Stopper::reset_counter(){
    st = clock();
}
