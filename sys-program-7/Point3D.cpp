#include "Point3D.h"

double Point3D::distanceTo(const Point3D& other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
}

double Point3D::distanceToOrigin() const {
    return sqrt(x * x + y * y + z * z);
}

bool Point3D::operator<(const Point3D& other) const {
    return distanceToOrigin() < other.distanceToOrigin();
}

void Point3D::move(double dx, double dy, double dz) {
    x += dx;
    y += dy;
    z += dz;
}

void Point3D::print() const {
    cout << "“очка (" << x << ", " << y << ", " << z << ")";
    cout << ", рассто€ние до начала координат: " << distanceToOrigin() << endl;
}