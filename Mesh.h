#pragma once
#include "Vector3.h"

struct Point;

struct Mesh {
    Mesh(Point* aPoint, Point* bPoint, Point* cPoint) : points{aPoint, bPoint, cPoint}
        {
            // for (Point* point : points) {
            //     point->meshes.push_back(this);
            // }
        };
    std::vector<Point*> points;
    Vector3 getNormalVector();
};
std::ostream& operator<<(std::ostream& os, const Mesh& mesh);
