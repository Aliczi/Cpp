#include <iostream>
#include "ElektrowniaWeglowa.h"

using namespace std;

// Konstruktor domyślny inicjalizujący wszystkie wskaźniki na wartość nullptr (podpunkt 8)
PowerPlant::PowerPlant():coal_feeder(nullptr),stock_level(nullptr),efficiency(nullptr),
                                        workforce(nullptr),produced_power(nullptr){
                                            log("Konstruktor domyslny\n");
                                            reset_counter();
                                        }

// Destruktor (podpunkt 9)
PowerPlant::~PowerPlant(){
    if (coal_feeder != nullptr) delete[] coal_feeder;
    if (stock_level != nullptr) delete[] stock_level;
    if (efficiency != nullptr) delete[] efficiency;
    if (workforce != nullptr) delete[] workforce;
    if (produced_power != nullptr) delete[] produced_power;
    log("Destruktor\n");
}

//Konstruktor kopiujący dokonujący głębokiej kopii (podpunkt 10)
PowerPlant::PowerPlant(const PowerPlant &p){
    if (p.coal_feeder == nullptr) coal_feeder = nullptr;
    else {
        coal_feeder = new double;
        *coal_feeder = *p.coal_feeder;
    }

    if (p.stock_level == nullptr) stock_level = nullptr;
    else {
        stock_level = new double;
        *stock_level = *p.stock_level;
    }
    
    if (p.efficiency == nullptr) efficiency = nullptr;
    else{
        efficiency = new double;
        *efficiency = *p.efficiency;
    }

    if (p.workforce ==nullptr) workforce = nullptr;
    else{
        workforce = new int;
        *workforce = *p.workforce;
    }

    if (p.produced_power == nullptr) produced_power = nullptr;
    else {
        produced_power = new double;
        *produced_power = *p.produced_power;
    }
    log("Konstruktor kopiujący\n");
    reset_counter();
}

//Konstruktor zgodny z semantyką move (podpunkt 11)
PowerPlant::PowerPlant(PowerPlant&& p) noexcept
:stock_level(nullptr),coal_feeder(nullptr),efficiency(nullptr),workforce(nullptr),produced_power(nullptr)
{
    stock_level = p.stock_level;
    coal_feeder = p.coal_feeder;
    efficiency = p.efficiency;
    workforce = p.workforce;
    produced_power = p.produced_power;

    p.stock_level = nullptr;
    p.coal_feeder = nullptr;
    p.efficiency = nullptr;
    p.workforce = nullptr;
    p.produced_power = nullptr;
    log("Konstruktor move\n");
    reset_counter();
}

//Konstruktor konwertujący (podpunkt 12)
PowerPlant::PowerPlant(double c):stock_level(nullptr),efficiency(nullptr),
                                        workforce(nullptr),produced_power(nullptr){
    coal_feeder=new double;
    *coal_feeder=c;
    log("Konstruktor konwertujący\n");
    reset_counter();
}

void PowerPlant::const_method() const {
    cout<<"Metoda const\n";
}

double PowerPlant::read_coal_feeder(){
    start_counter();
    if (coal_feeder == nullptr){
        coal_feeder = new double;
        cout<<"Podaj ilość węgla w podajniku: "<<endl;
        cin>>*coal_feeder;
    }
    log("Metoda read_coal_feeder\n");
    stop_counter();
    return *coal_feeder;
    }

void PowerPlant::add_to_stock(float i){
    start_counter();
        if (stock_level == nullptr){ 
            stock_level = new double;
            *stock_level = i;
        }
        else *stock_level = *stock_level + i;
    log("Metoda add_to_stock\n");
    stop_counter();
    }
    
bool PowerPlant::add_to_feeder(){
    start_counter();
        if (coal_feeder == nullptr){
            coal_feeder = new double;
            cout<<"Podaj ilość węgla w podajniku: "<<endl;
            cin>>*coal_feeder;
        }
        if (stock_level == nullptr){ 
            stock_level = new double;
            *stock_level = 0;
        }
        log("Metoda add_to_feeder\n");
        if (*stock_level>=*coal_feeder){
            *stock_level=*stock_level - *coal_feeder;
            stop_counter();
            return true;
        }
        
        else {stop_counter(); return false;}
    
    }

double PowerPlant::read_stock_level(){
    start_counter();
    if (stock_level == nullptr){ stock_level = new double; *stock_level = 0; }
    log("Metoda read_stock_level \n");
    stop_counter();
    return *stock_level;
    }
    
bool PowerPlant::set_efficiency(double a){
        start_counter();
        if (efficiency == nullptr) { efficiency = new double;}
        log("Metoda set_efficiency\n");
        if (a <=1 && a > 0) { *efficiency = a; stop_counter(); return true;}
        else {stop_counter(); return false; }
    }
    
double PowerPlant::read_efficiency(){
    start_counter();
    if (efficiency == nullptr) { efficiency = new double; *efficiency=0; }
    log("Metoda read_efficiency\n");
    stop_counter();
    return *efficiency;
    }

void PowerPlant::new_employees(int i){
    start_counter();
    if (workforce == nullptr) {
        workforce = new int;
        *workforce = i;
    }
    else *workforce=*workforce + i;
    log("Metoda new_employees\n");
    stop_counter();
    }

bool PowerPlant::fired_employees(int i){
    start_counter();
    if (workforce == nullptr) { workforce = new int, *workforce = 0;}
    log("Metoda fired_employees\n");
        if (i<=*workforce) { 
            *workforce=*workforce - i; 
            stop_counter();
            return true;
        }
        else {stop_counter(); return false;}
    }
    
int PowerPlant::read_workforce(){
    start_counter();
    if (workforce == nullptr) { workforce = new int, *workforce = 0;}
    log("Metoda read_workforce\n");
    stop_counter();
    return *workforce;
    }

//własne metody
void PowerPlant::calculate_produced_power(){
        start_counter();
        if (produced_power==nullptr){produced_power = new double;}
        if (coal_feeder == nullptr){
            coal_feeder = new double;
            cout<<"Podaj ilość węgla w podajniku: "<<endl;
            cin>>*coal_feeder;
        }
        if (efficiency == nullptr) { efficiency = new double; *efficiency=0; }
        *produced_power = *coal_feeder * (*efficiency); //obliczenie energii wyprodukowanej z węgla z jednego podajnika
        log("Metoda calculate_produced_power\n");
        stop_counter();
    }    
    
double PowerPlant::read_produced_power(){
        start_counter();
        if (produced_power==nullptr){produced_power = new double; *produced_power=0;}
        log("Metoda read_produced_power\n");
        stop_counter();
        return *produced_power;
    }