#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include "Vector3.h"
#include "Triplet.h"

template <typename T>
struct Buffer {
    void* data;
    int byteStride;
    int length;

    void iterateBuffer(std::vector<T*>* vector) {
        T* iterPtr = NULL;
        for (iterPtr = (T*)data; iterPtr < (data + length*byteStride); iterPtr++) {
            std::cout << "Pushed back : " << iterPtr << "\n";
            vector->push_back(iterPtr);
        }
    }
};
template <typename T>
std::ostream& operator<<(std::ostream& os, const Buffer<T> b) {
    os << "Buffer [";
    T* iterPtr = NULL;
    for (iterPtr = (T*)b.data; iterPtr < (b.data + b.length*b.byteStride); iterPtr++) {
        os << *iterPtr << ", ";
    }
    os << "]";
    return os;
}   


int main(int argc, char* argv[]) {
    std::vector<Point> points;
    std::vector<Triplet> triplets;

    points.emplace_back(Point{-1, -1, 0});
    points.emplace_back(Point{1, -1, 0});
    points.emplace_back(Point{1, 1, 0});
    points.emplace_back(Point{-1, 1, 0});
    triplets.push_back(Triplet{0, 1, 2});
    triplets.push_back(Triplet{0, 2, 3});

    Buffer<Point> P {&points[0], sizeof(Point), points.size()};
    Buffer<Triplet> T {&triplets[0], sizeof(Triplet), triplets.size()};

    std::vector<Point*> bufferPoints;
    std::vector<Triplet*> bufferTriplets;

    P.iterateBuffer(&bufferPoints);
    T.iterateBuffer(&bufferTriplets);

    for (auto& p : bufferPoints) {
        std::cout << "Adresse point récupéré : " << &p << " ";
        std::cout << "Point récupéré : " << *p << "\n";
    }
    
    std::vector<Triangle> triangles;

    for (auto& triplet : bufferTriplets) {
        triangles.emplace_back(Triangle(bufferPoints[triplet->a], bufferPoints[triplet->b], bufferPoints[triplet->c]));
    }

    for (auto& triangle : triangles) {
        for (auto& point : triangle.points) {
            point->addTriangle(&triangle);
        }
    }

    std::vector<Vector3> normalVectors;

    for (auto& point : bufferPoints) {
        normalVectors.push_back(point->getNormal());
    }

    Buffer<Vector3> N {&normalVectors[0], sizeof(Vector3), normalVectors.size()};

    std::cout << N << "\n";

    std::cout << "Finished.\n";
}
