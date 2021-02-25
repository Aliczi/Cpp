#include <iostream>
#include "osoba.h"
#include <string>

using namespace std;

Osoba::Osoba():name(nullptr),birth_date(nullptr),adress(nullptr){}

Osoba::~Osoba(){
    if (name != nullptr) delete name;
    if (birth_date != nullptr) delete birth_date;
    if (adress != nullptr) delete adress;
}

Osoba::Osoba(const Osoba &o){
    if (o.name == nullptr) name = nullptr;
    else {
        name = new string;
        *name = *o.name;
    }

    if (o.birth_date == nullptr) birth_date = nullptr;
    else {
        birth_date = new Date;
        *birth_date = *o.birth_date;
    }

    if (o.adress == nullptr) adress = nullptr;
    else {
        adress = new Adress;
        *adress = *o.adress;
    }
}
Osoba::Osoba(Osoba&& o) noexcept
:name(nullptr),birth_date(nullptr),adress(nullptr)
{
    name = o.name;
    birth_date = o.birth_date;
    adress = o.adress;

    o.name = nullptr;
    o.birth_date = nullptr;
    o.adress = nullptr;
}

Osoba::Osoba(string n):birth_date(nullptr),adress(nullptr){
    name = new string;
    *name = n;
}

void Osoba::set_name(string s)
{
    if (name == nullptr) name = new string;
    *name = s;
}

string Osoba::read_name()
{
    if (name == nullptr) return "Brak informacji";
    return *name;
} 

bool Osoba::set_birth_date(int d, int m, int y)
{
    if (birth_date == nullptr) birth_date = new Date;
    if (d>0 && m>0 && y>0){
       birth_date->day = d;
        birth_date->month = m;
        birth_date->year = y; 
        return true;
    }
    return false;   
}

void Osoba::read_birth_date()
{
    if (birth_date == nullptr) cout<< "Brak informacji";
    else {
        string dd,mm;
        if (birth_date->day<9)  dd="0"+to_string(birth_date->day);
        else dd=to_string(birth_date->day);
        if (birth_date->month<9) mm="0"+to_string(birth_date->month);
        else mm=to_string(birth_date->month);
        cout<<dd<<"."<<mm<<"."<<birth_date->year<<"r.";
    }

}

void Osoba::set_adress(string s,string n,string c,string code)
{
    if (adress == nullptr) adress = new Adress;
    adress->street = s;
    adress->number = n;
    adress->city = c;
    adress->postal_code = code;
}          
void Osoba::read_adress()
{
    if (adress == nullptr) cout<< "Brak informacji";
    else cout<<adress->street<<" "<<adress->number<<", "<<adress->postal_code<<" "<<adress->city;   
}

void Osoba::introduce()
{
    cout<<"Imię i nazwisko: "<<read_name(); cout<<endl;
    cout<<"Data urodzenia: "; read_birth_date(); cout<<endl;
    cout<<"Adres: "; read_adress(); cout<<endl;
    
}
