#include "Point.h"
#include "Triangle.h"
#include "Vector3.h"

void Point::addTriangle(Triangle* triangle) {
    triangles.push_back(triangle);
}

Vector3 Point::getNormal() {
    Vector3 normalVector;
    for (auto& triangle : triangles) {
        normalVector += triangle->getNormalVector();
    }
    return normalVector;
}

std::ostream& operator<<(std::ostream& os, const Point& point){
	os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
	return os;
}