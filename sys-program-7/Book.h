#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(const string& t = "", const string& a = "", int y = 0)
        : title(t), author(a), year(y) {
    }

    bool operator<(const Book& other) const { return year < other.year; }
    void print() const;

    bool saveToFile(const string& filename) const;
    bool loadFromFile(const string& filename);
};