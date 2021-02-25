#include <iostream>
#include "osoba.h"
#include "pracownik.h"
#include "student.h"
#include "fabrykaOsob.h"
#include "fabrykaStudentow.h"
#include "fabrykaPracownikow.h"
#include "vector"

using namespace std;

void foo(Osoba &os){
    os.introduce();
}

void bar(Osoba *os){
    os->introduce();
}

int main()
{
   
    Pracownik p;
    p.set_name("John Smith");
    p.set_birth_date(1,12,1999);
    p.set_adress("Polna","2","Gniezno","11-222");
    p.add_subject("angielski");
    p.add_subject("matematyka");
    p.add_subject("niemiecki");
    p.erase_subject("angielski");
    p.introduce();

    Student s;
    s.set_name("Max Mustermann");
    s.set_birth_date(5,6,1899);
    s.set_adress("Tytkowa","23","Leszno","55-522");
    s.add_grade("biologia",1);
    s.add_grade("matematyka",5);
    s.add_grade("chemia",3.5);
    s.introduce();

    // foo(o);
    // bar(&o);
    // foo(p);
    // bar(&p);
    // foo(s);
    // bar(&s);

    //27
    FabrykaStudentow fs;
    fs.utworz();
    FabrykaPracownikow fp;
    fp.utworz();

    //28
    map<string, FabrykaOsob*> m;
    m["pracownik"] = new FabrykaPracownikow();
    m["student"] = new FabrykaStudentow();

    vector<Osoba*> tablicaOsob;
    string currentCommand;
    bool end=false;
    while(!end){
        cout<<"Menu:\nstudent - wpisz, aby stworzyć nowy obiekt Student\npracownik - wpisz, aby stworzyć nowy obiekt Pracownik\ninne - wpisz, aby zakończyć"<<endl;
        cin>>currentCommand;
        if (currentCommand=="student" || currentCommand=="pracownik")
        tablicaOsob.push_back(m[currentCommand]->utworz());
        else end=true;
    }

    return 0;
}

/*
Podpunkt 12
Dla każdego obiektu została wywołana metoda introduce() zdefiniowana w klasie Osoba.
Nie zostały wykorzystane nadpisane metody z klas Pracownik i Student.
*/

/*
Podpunkt 14
Teraz dla każdego obiektu została wywołana dedykowana metoda introduce().
*/

/*
Podpunkt 15
Operatora static_cast można używać na potrzeby operacji takich jak konwertowanie wskaźnika
do klasy bazowej na wskaźnik do klasy pochodnej. Takie konwersje nie zawsze są bezpieczne,
gdyż static_cast nie sprawdza typów w czasie wykonywania. Zwykle static_cast używa się do typów niepolimorficznych i liczbowych typów danych.

Pracownik *p1 = new Pracownik;
Osoba *o1 = static_cast<Osoba *>(p1);       <- To konwersja w górę. Jest ona automatyczna i bezpieczna.
Osoba *o2 = static_cast<Pracownik *>(o1);   Trochę bezsensownie konwertować obiekt Osoba na Pracownik, 
żeby przypisać to znowu Osobie, ale nie spowoduje to błędów, gdyż Pracownik jest klasą pochodną klasy Osoba.

Osoba *o3 = new Osoba;
Pracownik *p2 = static_cast<Pracownik *>(o3);   <- Jako że static_cast nie sprawdza typów, zwróci taką wartość jakby się nic nie stało.
Jest to niebezpieczne, ponieważ Pracownik jest pochodną klasy Osoba i może mieć pola i metody, które nie znajdują się w klasie Osoba. 
To może spowodować różne błędy przy wywoływaniu funkcji klasy Pracownik, których nie ma w klasie Osoba.
*/


/* 
Podpunkt 16
dynamic_cast Używane do konwersji typów polimorficznych.

Pracownik *p3 = new Pracownik;
Osoba *o4 = dynamic_cast<Osoba *>(p3);          <- Przydatne, możemy sprawdzić, czy obiekt który podajemy jako argument faktycznie jest poprawny.
                                                    Jeśli nie jest, dynamic_cast zwróci nullptr.
Pracownik *p4 = dynamic_cast<Osoba *>(o4);      <-To wyrażenie nie jest poprawne. 
                                                Od razu wyskakuje błąd informujący że nie można użyć obiektu Osoba do zainicjowania obiektu Pracownik.

https://docs.microsoft.com/pl-pl/cpp/cpp/dynamic-cast-operator?view=msvc-160
https://cpp0x.pl/kursy/Programowanie-obiektowe-C++/Polimorfizm/Konwersja-w-gore-i-rzutowanie-w-dol/496
*/

/*
Podpunkt 17

   Osoba *o5 = new Osoba;
   Pracownik *p5 = dynamic_cast<Pracownik *>(o5);
   if (p5 == nullptr) cout << "Błąd rzutowania!" << endl;
   else cout << "Lista Przedmiotów";    <- nie wykona się 

Występuje błąd rzutowania, ponieważ dynamic_cast oczekuje obiektu typu Pracownik a nie Osoba.
Z tego dynamic_cast zwraca pusty wskaźnik, a na wyjściu jest wypisywany "Błąd rzutowania".

Używanie dynamic_cast != nullptr niesie ryzyko błędnego porównania.
*/

/*
Podpunkt 19
Nie mogę skompilować projektu. Klasa Osoba posiada teraz jedną czystą funkcję wirtualną.
Z tego powodu jest to klasa abstrakcyjna i nie możemy tworzyć obiektów tego typu.
Wystarczy np. zmienić typ obiektu Osoba na którąś z jej klas pochodnych.
*/

/*
Podpunkt 22
Program działa poprawnie, aczkolwiek jest niestabilny i jego zachowanie jest niezdefiniowane.
*/

/*
Podpunkt 23
Teraz destruktory będą wywoływane w kolejności od najbardziej pochodnych aż do bazowego.
*/

/*
Podpunkt 30
Definiujemy kontener z kluczem o typie string oraz wartością o typie wskaźnik na FabrykeOsob.
Z tego powodu przy dodawaniu klucza z wartością musimy użyć new.
*/

/*
Podpunkt 33
Otrzymaliśmy kontener w którym możemy przechowywać obiekty różnych typów dziedziczących po tej samej klasie wirtualnej.
Kod jest zwarty i czytelny.
*/