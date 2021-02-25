#include <iostream>
#include "pracownik.h"

using namespace std;

Pracownik::Pracownik():subjects(nullptr),Osoba(){};
Pracownik::~Pracownik(){
    if (subjects != nullptr) delete subjects;
}

Pracownik::Pracownik(string s):subjects(nullptr),Osoba(s){};
Pracownik::Pracownik(Pracownik&& p) noexcept
:subjects(nullptr), Osoba(p){
    subjects = p.subjects;
    p.subjects = nullptr;
}
Pracownik::Pracownik(const Pracownik& p):Osoba(p){
    if (p.subjects==nullptr) subjects = nullptr;
    else {
        *subjects = *p.subjects;
    }
}

void Pracownik::add_subject(string sub){
    if (subjects == nullptr) subjects = new set<string>;
    if (!check_subject(sub))
        subjects->insert(sub);
}

void Pracownik::erase_subject(string sub){
    if (subjects == nullptr) subjects = new set<string>;
    subjects->erase(sub);
}

bool Pracownik::check_subject(string sub){
    if (subjects == nullptr) subjects = new set<string>;
    if (subjects->find(sub) != subjects->end()){
        return true;
    }
    return false;
}

void Pracownik::introduce(){
    cout<<endl<<"Imię i nazwisko: "<<read_name(); cout<<endl;
    cout<<"Data urodzenia: "; read_birth_date(); cout<<endl;
    cout<<"Adres: "; read_adress(); cout<<endl;
    cout<<"Zajęcie: pracownik."<<endl;
    cout<<"Nauczane przedmioty: ";
    if (subjects == nullptr) cout<< "Brak informacji";
    else {
        for (auto it = subjects->begin(); it != subjects->end(); ++it)
            if (it != subjects->begin()) cout<< ", " << *it;
            else cout << *it;
    }
    cout<<"."<<endl;
}