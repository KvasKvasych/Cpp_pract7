#include "Complex.h"

Complex::Complex(double r, double i) : real(r), imag(i) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag,
        real * other.imag + imag * other.real);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    return Complex((real * other.real + imag * other.imag) / denominator,
        (imag * other.real - real * other.imag) / denominator);
}

double Complex::modulus() const {
    return sqrt(real * real + imag * imag);
}

bool Complex::operator<(const Complex& other) const {
    return modulus() < other.modulus();
}

void Complex::print() const {
    cout << real;
    if (imag >= 0) {
        cout << " + " << imag << "i";
    }
    else {
        cout << " - " << -imag << "i";
    }
}