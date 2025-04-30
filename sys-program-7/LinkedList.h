#pragma once
#include <iostream>
#include <string>

using namespace std;

class LinkedList {
private:
    struct Node {
        string data;
        Node* next;
        Node(const string& val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList();

    void append(const string& value);
    bool remove(const string& value);
    bool contains(const string& value) const;
    void print() const;
    int getSize() const { return size; }
};