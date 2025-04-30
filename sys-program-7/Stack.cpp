#include "Stack.h"

Stack::Stack(int initialCapacity)
    : capacity(initialCapacity), topIndex(-1) {
    data = new int[capacity];
}

Stack::~Stack() {
    delete[] data;
}

void Stack::resize(int newCapacity) {
    int* newData = new int[newCapacity];
    for (int i = 0; i <= topIndex; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void Stack::push(int value) {
    if (topIndex == capacity - 1) {
        resize(capacity * 2);
    }
    data[++topIndex] = value;
}

int Stack::pop() {
    if (isEmpty()) {
        throw out_of_range("Стек пуст");
    }
    return data[topIndex--];
}

bool Stack::isEmpty() const {
    return topIndex == -1;
}

int Stack::peek() const {
    if (isEmpty()) {
        throw out_of_range("Стек пуст");
    }
    return data[topIndex];
}

void Stack::print() const {
    if (isEmpty()) {
        cout << "Стек пуст" << endl;
        return;
    }

    cout << "Содержимое стека (сверху вниз):" << endl;
    for (int i = topIndex; i >= 0; --i) {
        cout << data[i] << endl;
    }
}