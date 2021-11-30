#include <iostream>
#include "Point.h"
#include "Mesh.h"
#include "Vector3.h"
#include "Triplet.h"

struct Buffer {
    void* data;
    int byteStride;
    int length;

    template<typename T> void iterateBuffer(std::vector<T*>* vector) {
        T* iterPtr = NULL;
        for (iterPtr = (T*)data; iterPtr < (data + length*byteStride); iterPtr++) {
            std::cout << "Pushed back : " << iterPtr << "\n";
            vector->push_back(iterPtr);
        }
    }

    template<typename T> void print() {
        std::cout << "Buffer [";
        T* iterPtr = NULL;
        for (iterPtr = (T*)data; iterPtr < (data + length*byteStride); iterPtr++) {
            std::cout << *iterPtr << ", ";
        }
        std::cout << "]\n";
    }   
};



int main(int argc, char* argv[]) {
    std::vector<Point> points;
    std::vector<Triplet> triplets;

    points.emplace_back(Point{-1, -1, 0});
    points.emplace_back(Point{1, -1, 0});
    points.emplace_back(Point{1, 1, 0});
    points.emplace_back(Point{-1, 1, 0});
    triplets.push_back(Triplet{0, 1, 2});
    triplets.push_back(Triplet{0, 2, 3});

    Buffer P {&points[0], sizeof(Point), points.size()};
    Buffer T {&triplets[0], sizeof(Triplet), triplets.size()};

    std::vector<Point*> bufferPoints;
    std::vector<Triplet*> bufferTriplets;

    P.iterateBuffer<Point>(&bufferPoints);
    T.iterateBuffer<Triplet>(&bufferTriplets);

    for (auto& p : bufferPoints) {
        std::cout << "Adresse point récupéré : " << &p << " ";
        std::cout << "Point récupéré : " << *p << "\n";
    }
    
    std::vector<Mesh> meshes;

    std::cout << "Amount of triplets : " << bufferTriplets.size() << "\n";

    for (int i = 0; i < bufferTriplets.size(); i++) {
        meshes.emplace_back(Mesh(bufferPoints[bufferTriplets[i]->a], bufferPoints[bufferTriplets[i]->b], bufferPoints[bufferTriplets[i]->c]));
    }

    for (auto& mesh : meshes) {
        for (auto& point : mesh.points) {
            point->addMesh(&mesh);
        }
    }

    std::vector<Vector3> normalVectors;

    for (auto& point : bufferPoints) {
        normalVectors.push_back(point->getNormal());
    }

    Buffer N {&normalVectors[0], sizeof(Vector3), normalVectors.size()};

    N.print<Vector3>();

    std::cout << "Finished.\n";
}
