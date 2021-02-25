#include <iostream>
#include "ElektrowniaWeglowa.h"
#include <chrono>
#include <thread>

using namespace std;

void foo(PowerPlant);
void bar ( const PowerPlant& );
void baz (PowerPlant&);
void qux (PowerPlant&&);


int main(){
    PowerPlant e;
    cout<<e.read_coal_feeder()<<endl;
    e.add_to_stock(120.0);
    e.add_to_feeder();
    cout<<e.read_stock_level()<<endl;
    e.set_efficiency(0.1);
    cout<<e.read_efficiency()<<endl;
    e.new_employees(4);
    e.fired_employees(2);
    e.fired_employees(3);
    cout<<e.read_workforce()<<endl;
    e.calculate_produced_power();
    cout<<e.read_produced_power()<<endl;

    /*
    foo(e); //podpunkt 15
    foo(move(e)); //podpunkt 16
    foo(4); //podpunkt 17
    */

    /*
    bar(e); 
    bar(move(e)); 
    bar(4); 
    */

    baz(e);
    //baz(move(e));     //niepoprawnie
    //baz(4);   //niepoprawnie

    //qux(e); //niepoprawnie
    qux(move(e));
    qux(4);
    

    e.log("Wywołanie metody log z poziomu funkcji main");
    e.read_coal_feeder();

    //31
    int k=0;
    while(k<4){
        e.add_to_stock(200.0);
        e.get_count();
        e.add_to_feeder();
        e.get_count();
        e.read_stock_level();
        e.get_count();
        e.set_efficiency(0.6);
        e.get_count();
        e.read_efficiency();
        e.get_count();
        e.new_employees(4);
        e.get_count();
        e.fired_employees(2);
        e.get_count();
        e.read_workforce();
        e.get_count();
        e.calculate_produced_power();
        e.get_count();
        e.read_produced_power();
        e.get_count();
        k++;
        e.start_counter();
        this_thread::sleep_for(chrono::milliseconds(200));
        e.stop_counter();
        e.get_count();
    }

    return 0; 
}

void foo ( PowerPlant p ) {
    cout<<"Funkcja foo biorąca za argument obiekt klasy PowerPlant"<<endl;
    cout<<p.read_coal_feeder()<<endl;
    p.add_to_stock(500);
}

void bar ( const PowerPlant &p ) {
    PowerPlant a = p;
    cout<<"Funkcja bar biorąca za argument obiekt poprzez L-value"<<endl;
    p.const_method();
    //cout<< a.read_coal_feeder()<<endl; poprawnie
    // cout<< p.read_coal_feeder()<<endl; //niepoprawnie
}

/*
Obserwacje do podpunktu 19:
Nie można modyfikować obiektu p. Możemy używać metod const (ang. const member functions).
bar(move(e)) nie wywołuje konstruktora z pliku ElektrowniaWeglowa.cpp.
Konstruktor kopiujący i konwertujący działają poprawnie.
*/

void baz ( PowerPlant &p ) {
    cout<<"Funkcja baz biorąca za argument obiekt zwykłej referencji L-value"<<endl;
    cout<< p.read_coal_feeder()<<endl;
    p.add_to_stock(500);
}

/*
Obserwacje do podpunktu 21:
Dla baz(e) nie wywołuje się konstruktor kopiujący. Działamy na obiekcie podanym w argumencie.
baz(move(e)) oraz baz(4) nie kompilują się 
*/

void qux ( PowerPlant &&p ) {
    cout<<"Funkcja qux biorąca za argument obiekt referencji R-value"<<endl;
    cout<< p.read_coal_feeder()<<endl;
}

/* 
Obserwacje do podpunktu 23:
qux(e) nie działa ponieważ nie możemy odwoływac się do r-value używając l-value.
W qux(move(e)) pracujemy na podanym obiekcie.
qux(e) wywołuje kontruktor konwertujący i tworzy nowy obiekt
*/

/*
Odpowiedź do podpunktu 26
Z poziomu funkcji main nie mogę wywołać metody log obiektu implementowanej klasy. Wyskakuje komentarz, że element jest niedostepny.
Mogę używać metody log z poziomu funkcji main, jeśli dopiszę przy dziedziczeniu klasy słówko public (class PowerPlant: public Logger { //... }).
Wyniki to z różnych rodzajów dziedziczenia:
dziedziczenie publiczne (:public) --> rodzaje dostępu przy dziedziczeniu składników nie ulegają zmianie
dziedziczenie chronione (:protected) --> składniki public stają się protected
dziedziczenie prywatne, domyślne (:private) --> składniki public oraz protected stają się private
*/

/*
Odpowiedź do podpunktu 27
Podczas korzystania z metody log w klasie PowerPlant zostaje wywołana metoda z log z pliku Logger.cpp
*/

/* 
odpowiedź do podpunktu 29
Nie mogę teraz skompilować projektu. Przyczyną są błędy w konstruktorach klas, które dziedziczą z klasy Logger.
Rozwiązaniem problemu było dodanie do klasy Logger konstruktora domyślnego.
*/

/*
Odpowiedź do podpunktu 32
Dziedziczenie po dwóch lub kilku klasach niesie m.in. ryzyko przysłaniana funkcji o tych samych nazwach z klas dziedziczonych. 
Ponadto zmieniając jedną klasę, wpływamy na wszystkie klasy które po niej dziedziczą, co może prowadzić do łańcucha błędów i utrudniać zrozumienie przyczyny.
*/