#include "Stack.h"
#include <vector>
#include "wyjatki.h"


Stack::Stack(){
    top = -1;
    maxStackSize = 10;
    std::vector<int> dfs(10);
}

Stack::Stack(int max):maxStackSize(max){
    top = -1;
    std::vector<int> dfs(max);
}

void Stack::push(int newItem){
    if (this->top == this->maxStackSize -1) {throw StackFullException("Wyjątek. Pełny stos.", newItem, maxStackSize);}
    this->dfs.push_back(newItem);
    top++;
}

int Stack::pop(){
    if (top == -1) throw StackEmptyException("Wyjątek. Pusty stos.");
    top--;
    int p = dfs.back();
    dfs.pop_back();
    return p;
}