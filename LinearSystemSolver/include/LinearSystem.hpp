#ifndef LINEARSYSTEM_HPP
#define LINEARSYSTEM_HPP

#include <vector>
#include "Vector.hpp"

class LinearSystem {
public:
    LinearSystem(const std::vector<std::vector<double>>& coefficients, const std::vector<double>& constants);
    Vector solve() const;

private:
    std::vector<std::vector<double>> coefficients;
    Vector constants;
};

#endif // LINEARSYSTEM_HPP
