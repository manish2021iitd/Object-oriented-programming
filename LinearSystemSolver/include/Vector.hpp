#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

class Vector {
public:
    Vector(int size);
    Vector(const std::vector<double>& elements);
    double& operator[](int index);
    const double& operator[](int index) const;
    int size() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    double dot(const Vector& other) const;

private:
    std::vector<double> elements;
};

#endif // VECTOR_HPP
