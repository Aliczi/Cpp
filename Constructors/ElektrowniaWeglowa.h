#pragma once
#include <iostream>
#include "Logger.h"
#include "Stopper.h"

using namespace std;

class PowerPlant: public Logger, public Stopper{
    double* coal_feeder; //maksymalna ilość węgla w podajniku
    double* stock_level; //stan magazynowy węgla
    double* efficiency; //sprawność elektrowni
    int* workforce; //liczba pracowników
    double* produced_power; //wyprodukowana energia


    public:
    PowerPlant();
    ~PowerPlant();
    PowerPlant(const PowerPlant& );
    PowerPlant(PowerPlant&&) noexcept;
    PowerPlant(double);
    void const_method() const;
    double read_coal_feeder();
    void add_to_stock(float);
    bool add_to_feeder();
    double read_stock_level();
    bool set_efficiency(double);
    double read_efficiency();
    void new_employees(int);
    bool fired_employees(int);
    int read_workforce();
    void calculate_produced_power();
    double read_produced_power();
};