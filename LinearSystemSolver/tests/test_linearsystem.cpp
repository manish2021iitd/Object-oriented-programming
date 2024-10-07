#include <iostream>
#include "LinearSystem.hpp"

void testLinearSystem() {
    std::vector<std::vector<double>> coefficients = {
        {2.0, 1.0},
        {1.0, -1.0}
    };
    std::vector<double> constants = {3.0, 0.0};

    LinearSystem system(coefficients, constants);
    Vector solution = system.solve();
    
    std::cout << "Solution: ";
    for (int i = 0; i < solution.size(); i++) {
        std::cout << solution[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    testLinearSystem();
    return 0;
}
