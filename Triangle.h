#pragma once
#include "Vector3.h"

struct Point;

struct Triangle {
    Triangle(Point* aPoint, Point* bPoint, Point* cPoint) : points{aPoint, bPoint, cPoint}
        {
        };
    std::vector<Point*> points;
    Vector3 getNormalVector();
};
std::ostream& operator<<(std::ostream& os, const Triangle& triangle);
