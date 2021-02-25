#include <iostream>
#include <string.h>
#include <map>
#include "osoba.h"

using namespace std;

class Student: public Osoba{
    map<string,double> *grades;

    public:
    Student();
    ~Student();
    Student(const Student&);
    Student(Student&&) noexcept;
    Student(string);
    void add_grade(string, double);
    double read_grade(string);
    void read_all_grades();
    void introduce();
};