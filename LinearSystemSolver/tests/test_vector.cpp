#include <iostream>
#include "Vector.hpp"

void testVector() {
    Vector v1(3);
    v1[0] = 1.0;
    v1[1] = 2.0;
    v1[2] = 3.0;

    Vector v2({4.0, 5.0, 6.0});

    Vector v3 = v1 + v2;
    std::cout << "v3: ";
    for (int i = 0; i < v3.size(); i++) {
        std::cout << v3[i] << " ";
    }
    std::cout << std::endl;

    Vector v4 = v1 - v2;
    std::cout << "v4: ";
    for (int i = 0; i < v4.size(); i++) {
        std::cout << v4[i] << " ";
    }
    std::cout << std::endl;

    double dotProduct = v1.dot(v2);
    std::cout << "Dot Product: " << dotProduct << std::endl;
}

int main() {
    testVector();
    return 0;
}
