#include "Mesh.h"
#include "Point.h"
#include <iostream>

Vector3 Mesh::getNormalVector() {
    return Vector3::crossProduct(Vector3(points[1], points[0]), Vector3(points[2], points[0]));
}
std::ostream& operator<<(std::ostream& os, const Mesh& mesh) {
    std::cout << "Mesh : [";
    for (Point* p : mesh.points) {
        std::cout << *p << ", ";
    }
    std::cout << "]";
}
