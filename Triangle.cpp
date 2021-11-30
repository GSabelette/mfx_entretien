#include "Triangle.h"
#include "Point.h"
#include <iostream>

Vector3 Triangle::getNormalVector() {
    return Vector3::crossProduct(Vector3(points[1], points[0]), Vector3(points[2], points[0]));
}
std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
    os << "Triangle : [";
    for (Point* p : triangle.points) {
        os << *p << ", ";
    }
    os << "]";
    return os;
}
