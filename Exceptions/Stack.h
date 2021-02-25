#pragma once
#include <iostream>
#include<vector>

class Stack{
    int maxStackSize;
    int top;
    std::vector<int> dfs;

    public:
    Stack();
    Stack(int);
    void push(int);
    int pop();
};

