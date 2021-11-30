#include "Point.h"
#include "Mesh.h"
#include "Vector3.h"

void Point::addMesh(Mesh* mesh) {
    meshes.push_back(mesh);
}

Vector3 Point::getNormal() {
    Vector3 normalVector;
    for (auto mesh : meshes) {
        normalVector += mesh->getNormalVector();
    }
    return normalVector;
}

std::ostream& operator<<(std::ostream& os, const Point& point){
	os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
	return os;
}