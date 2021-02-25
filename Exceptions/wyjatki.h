#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class StackException: public std::exception{
    public:
    StackException(){}
    virtual const char* what() const noexcept override;
};


class StackFullException: public StackException{
    int element = 0;
    int maxStackSize = 0;
    string message;
    string a;
    public:
    StackFullException();
    StackFullException(string, int, int);
    virtual const char* what() const noexcept override;
};


class StackEmptyException : public StackException{
    string message;
    public:
    StackEmptyException(){}
    StackEmptyException(string);
    virtual const char* what() const noexcept override;
};


