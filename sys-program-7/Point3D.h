#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point3D {
private:
    double x, y, z;

public:
    Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    double distanceTo(const Point3D& other) const;
    double distanceToOrigin() const;
    bool operator<(const Point3D& other) const;
    void move(double dx, double dy, double dz);

    void print() const;
};