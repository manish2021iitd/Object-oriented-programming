#include <cassert>
#include "Matrix.hpp"

int main() {
    Matrix A(2, 2);
    A(1, 1) = 3; A(1, 2) = 2;
    A(2, 1) = 1; A(2, 2) = 4;
    
    Matrix B(2, 2);
    B(1, 1) = 2; B(1, 2) = 1;
    B(2, 1) = 0; B(2, 2) = 3;
    
    Matrix C = A + B;
    
    assert(C(1, 1) == 5);
    assert(C(1, 2) == 3);
    assert(C(2, 1) == 1);
    assert(C(2, 2) == 7);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
