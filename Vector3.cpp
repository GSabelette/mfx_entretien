#include "Vector3.h"

Vector3::Vector3(const Point* aPoint, const Point* bPoint) {
    xAxis = bPoint->x - aPoint->x;
    yAxis = bPoint->y - aPoint->y;
    zAxis = bPoint->z - aPoint->z;
}

Vector3 Vector3::operator+(const Vector3 &right) const{
	Vector3 temp(*this);
	temp += right;
	return temp;
}

Vector3 Vector3::operator-(const Vector3 &right) const{
	Vector3 temp(*this);
	temp -= right;
	return temp;
}

Vector3& Vector3::operator+=(const Vector3 &right){
	xAxis += right.xAxis;
    yAxis += right.yAxis;
    zAxis += right.zAxis;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3 &right){
	xAxis -= right.xAxis;
    yAxis -= right.yAxis;
    zAxis -= right.zAxis;
	return *this;
}

Vector3 Vector3::crossProduct(const Vector3 &left, const Vector3 &right){
	return Vector3(
		left.yAxis*right.zAxis - left.zAxis*right.yAxis ,
		left.zAxis*right.xAxis - left.xAxis*right.zAxis ,
		left.xAxis*right.yAxis - left.yAxis*right.xAxis );
}

std::ostream& operator<<(std::ostream& os, const Vector3& vector3){
	os << "{" << vector3.xAxis << ", " << vector3.yAxis << ", " << vector3.zAxis << "}";
	return os;
}