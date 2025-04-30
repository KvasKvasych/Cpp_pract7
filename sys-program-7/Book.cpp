#include "Book.h"

void Book::print() const {
    cout << "Книга: \"" << title << "\", автор: " << author
        << ", год издания: " << year << endl;
}

bool Book::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) return false;

    outFile << title << endl;
    outFile << author << endl;
    outFile << year << endl;

    return outFile.good();
}

bool Book::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) return false;

    getline(inFile, title);
    getline(inFile, author);
    inFile >> year;

    return inFile.good();
}