#pragma once
#include <vector>
#include <iostream>
struct Triangle;
struct Vector3;

struct Point {
    Point(const long x, const long y, const long z) : x(x), y(y), z(z) {triangles = std::vector<Triangle*>();};
    long x;
    long y;
    long z;
    std::vector<Triangle*> triangles;
    Vector3 getNormal();
    void addTriangle(Triangle* triangle);
};
std::ostream& operator<<(std::ostream& os, const Point& point);