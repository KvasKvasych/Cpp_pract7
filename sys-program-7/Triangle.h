#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Triangle {
private:
    double sideA, sideB, sideC;

    bool isValid() const {
        return (sideA + sideB > sideC) &&
            (sideA + sideC > sideB) &&
            (sideB + sideC > sideA);
    }

public:
    Triangle(double a = 1, double b = 1, double c = 1) : sideA(a), sideB(b), sideC(c) {
        if (!isValid()) {
            throw invalid_argument("Невозможно создать треугольник с такими сторонами");
        }
    }

    double perimeter() const {
        return sideA + sideB + sideC;
    }

    double area() const {
        double p = perimeter() / 2;
        return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
    }

    bool isIsosceles() const {
        return (sideA == sideB) || (sideA == sideC) || (sideB == sideC);
    }

    bool isEquilateral() const {
        return (sideA == sideB) && (sideB == sideC);
    }

    bool operator<(const Triangle& other) const {
        return area() < other.area();
    }

    void print() const {
        cout << "Треугольник со сторонами: " << sideA << ", " << sideB << ", " << sideC << endl;
        cout << "Периметр: " << perimeter() << endl;
        cout << "Площадь: " << area() << endl;
        cout << "Равнобедренный: " << (isIsosceles() ? "да" : "нет") << endl;
        cout << "Равносторонний: " << (isEquilateral() ? "да" : "нет") << endl;
    }
};