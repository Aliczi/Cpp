#include <iostream>
#include "student.h"

Student::Student():grades(nullptr),Osoba(){}
Student::~Student(){
    if(grades != nullptr) delete grades;
}
Student::Student(string s):grades(nullptr),Osoba(s){};
Student::Student(Student&& s) noexcept
:grades(nullptr), Osoba(s){
    grades = s.grades;
    s.grades = nullptr;
}
Student::Student(const Student& s):Osoba(s){
    if (s.grades==nullptr) grades = nullptr;
    else {
        *grades = *s.grades;
    }
}


void Student::add_grade(string sub, double val){
    if (grades == nullptr) grades = new map<string,double>;
    if (val >=1 && val <= 5)
        grades->insert(std::make_pair(sub,val));
}

double Student::read_grade(string sub){
    if (grades == nullptr) grades = new map<string,double>;
    if( grades->find(sub) != grades->end()) return (*grades)[sub];
    return 0;
}

void Student::read_all_grades(){
    if (grades == nullptr) grades = new map<string,double>;
    map<string,double>::iterator it;
    for (it = grades->begin(); it != grades->end(); it++){
        cout<< it-> first << ": " << it ->second <<endl;
    }
}

void Student::introduce(){
    cout<<endl<<"Imię i nazwisko: "<<read_name(); cout<<endl;
    cout<<"Data urodzenia: "; read_birth_date(); cout<<endl;
    cout<<"Adres: "; read_adress(); cout<<endl;
    cout<<"Zajęcie: student."<<endl;
    cout<<"Zdobyte oceny: "<<endl;
    read_all_grades();
}