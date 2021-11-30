#pragma once
#include "Point.h"
#include <iostream>

struct Vector3 {
    Vector3() : xAxis(0), yAxis(0), zAxis(0) {};
    Vector3(const long xAxis, const long yAxis, const long zAxis) : xAxis(xAxis), yAxis(yAxis), zAxis(zAxis) {};
    Vector3(const Point* aPoint, const Point* bPoint);
    long xAxis;
    long yAxis;
    long zAxis;

    Vector3 operator+(const Vector3 &right) const;
    Vector3 operator-(const Vector3 &right) const;
    Vector3& operator+=(const Vector3 &right);
	Vector3& operator-=(const Vector3 &right);
    static Vector3 crossProduct(const Vector3 &left, const Vector3 &right);
};
std::ostream& operator<<(std::ostream& os, const Vector3& vector3);
