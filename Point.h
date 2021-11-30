#pragma once
#include <vector>
#include <iostream>
struct Mesh;
struct Vector3;

struct Point {
    Point(const long x, const long y, const long z) : x(x), y(y), z(z) {meshes = std::vector<Mesh*>();};
    long x;
    long y;
    long z;
    std::vector<Mesh*> meshes;
    Vector3 getNormal();
    void addMesh(Mesh* mesh);
};
std::ostream& operator<<(std::ostream& os, const Point& point);