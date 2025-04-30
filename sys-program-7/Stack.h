#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class Stack {
private:
    int* data;
    int capacity;
    int topIndex;

    void resize(int newCapacity);

public:
    Stack(int initialCapacity = 10);
    ~Stack();

    void push(int value);
    int pop();
    bool isEmpty() const;
    int peek() const;

    void print() const;
};