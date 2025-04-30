#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    double modulus() const;
    bool operator<(const Complex& other) const;

    void print() const;
};