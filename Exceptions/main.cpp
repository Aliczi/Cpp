#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <cstring>
#include "Stack.h"
#include "wyjatki.h"

using namespace std;

void foo(Stack &s){
    try{
        s.push(11);
    } catch (StackException e){
        cout<< e.what() <<endl;
    }
}
void bar(Stack &s){
    try{
        s.push(11);
    } catch (StackException &e){
        cout<< e.what() <<endl;
    }
}

int main(){
    Stack s(5);
    try{
        s.pop();
    } catch (StackException &e){
        cout<< e.what() <<endl;
    }

    for (int i =0; i<6; i++) foo(s);
    for (int i = 0; i<2; i++) bar(s);

    bool loop=true;
    int option, size;
    cout<<"Podaj rozmiar stosu:\t"; cin>>size;
    Stack stack(size);
    while(loop){
        try{
            cout<<"\n1 - Dodaj\n2 - Usun\ninne - Wyjdz\n";
            fflush(stdin);
            cin>>option;
            switch (option)
            {
            case 1:
            int el;
            cout<<"Podaj element:\t"; 
            if (scanf("%d",&el) != 1) throw invalid_argument("Element stosu powinien byc typu int");
                stack.push(el);
                break;
            case 2:
            cout<<"Ze stosu usunieto:\t"<<stack.pop();
                break;
            default:
                loop=false;
                break;
            }
        } catch (StackException &e){
            cout<<e.what()<<endl;
        } catch (invalid_argument iaex){
            cout<< iaex.what() <<endl;
        } catch (exception &e){
            cout<<"Inny wyjatek"<<endl;
        }
    }

}

/*
Podpunkt 3
override - zapewnia to, że funkcja jest wirtualna i nadpisuje funkcję wirtualną z klasy bazowej
noexcept - wyrażenie, funkcja jest zadeklarowana, że nie będzie wyrzucać wyjątków. 
*/

/*
Podpunkt 4
W cpp wyjątki są obsługiwane po kompilacji, w trakcie wykonywania programu.
W przeciwieństwie do Javy, gdzie wyjątki są obslugiwane na etapie kompilacji.
*/

/*
Podpunkt 5
Została wywołana funkcja what() z klasy abstrakcyjnej. 
Zamiast odnieść się do złapanego wyjątku, stworzyliśmy nowy za pomocą konstruktora domyślnego.
*/

/*
Podpunkt 6
Została wywołana odpowiednia funkcja what(), od tego obiektu który został rzucony w metdzie.
& oznacza referencję na jakiś obiekt z klasy StackException
*/

