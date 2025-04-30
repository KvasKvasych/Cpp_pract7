#pragma once
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

class QuadraticEquation {
private:
    double a, b, c;

public:
    QuadraticEquation(double a = 1, double b = 0, double c = 0) : a(a), b(b), c(c) {
        if (a == 0) {
            throw invalid_argument("Коэффициент 'a' не может быть нулевым");
        }
    }

    pair<complex<double>, complex<double>> roots() const {
        double discriminant = b * b - 4 * a * c;
        complex<double> root1 = (-b + sqrt(complex<double>(discriminant))) / (2 * a);
        complex<double> root2 = (-b - sqrt(complex<double>(discriminant))) / (2 * a);
        return make_pair(root1, root2);
    }

    bool hasRealRoots() const {
        return (b * b - 4 * a * c) >= 0;
    }

    void print() const {
        cout << "Уравнение: ";
        cout << a << "x²";
        if (b != 0) cout << " + " << b << "x";
        if (c != 0) cout << " + " << c;
        cout << " = 0" << endl;

        auto r = roots();
        cout << "Корни: " << r.first << " и " << r.second << endl;
        cout << "Действительные корни: " << (hasRealRoots() ? "да" : "нет") << endl;
    }
};