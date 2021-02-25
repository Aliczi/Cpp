#include <iostream>
#include <string.h>
#pragma once

using namespace std;

class Adress
{
    string street;
    string number;
    string city;
    string postal_code;
    friend class Osoba;
};

struct Date
{
    int day;
    int month;
    int year;
};

class Osoba
{
    string* name;
    Date* birth_date;
    Adress* adress;
    
    public:
    Osoba();
    virtual ~Osoba();
    Osoba(const Osoba&);
    Osoba(Osoba&&) noexcept;
    Osoba(string);
    void set_name(string);
    string read_name();
    bool set_birth_date(int, int, int);
    void read_birth_date();
    void set_adress(string, string, string, string);          
    void read_adress();
    virtual void introduce() = 0 ;
};