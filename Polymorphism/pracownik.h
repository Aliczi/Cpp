#include <iostream>
#include <string.h>
#include <set>
#include "osoba.h"
#pragma once

using namespace std;

class Pracownik: public Osoba{
    set<string> *subjects;
    public:
    Pracownik();
    ~Pracownik();
    Pracownik(const Pracownik&);
    Pracownik(Pracownik&&) noexcept;
    Pracownik(string);
    void add_subject(string);
    void erase_subject(string);
    bool check_subject(string);
    void introduce();   
};