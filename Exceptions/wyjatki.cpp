#include "wyjatki.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const char* StackException::what() const noexcept{
    return "Bardzo biedna operacja na stosie!";
}

StackFullException::StackFullException(string p, int e, int s){
    message = p;
    maxStackSize = s;
    element = e;
}

const char* StackFullException::what() const noexcept {
    string s = message+" Rozmiar stosu: " + to_string(maxStackSize) + ". Nadmiarowy element: " + to_string(element);
    char *c = new char[ s.length()+1 ];
    strcpy(c,s.c_str());                                   //never return a pointer to a local variable.
    return c;                                              //https://www.fayewilliams.com/20/15/06/30/a-challenge-discussion-returning-pointers-to-local-variables/
}

StackEmptyException::StackEmptyException(string p){
    message = p;
}

const char* StackEmptyException::what() const noexcept {
        return &message[0];
    }

