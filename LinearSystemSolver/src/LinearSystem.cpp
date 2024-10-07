#include "LinearSystem.hpp"
#include <cassert>
#include <cmath>

LinearSystem::LinearSystem(Matrix* matrixA, Vector* vectorB) : mSize(matrixA->GetnumRows()), mpA(matrixA), mpb(vectorB) {}

LinearSystem::~LinearSystem() {}

Vector LinearSystem::Solve() {
    Vector solution(mSize);

    Matrix& rA = *mpA;
    Vector& rb = *mpb;

    // Gaussian elimination with partial pivoting
    for (int k = 0; k < mSize - 1; k++) {
        double max = 0.0;
        int row = -1;
        for (int i = k; i < mSize; i++) {
            if (fabs(rA(i + 1, k + 1)) > max) {
                row = i;
                max = fabs(rA(i + 1, k + 1));
            }
        }
        assert(row != -1);  // Ensure the matrix is non-singular

        // Swap rows if needed
        if (row != k) {
            for (int j = 0; j < mSize; j++) {
                double temp = rA(k + 1, j + 1);
                rA(k + 1, j + 1) = rA(row + 1, j + 1);
                rA(row + 1, j + 1) = temp;
            }
            double tempB = rb(k + 1);
            rb(k + 1) = rb(row + 1);
            rb(row + 1) = tempB;
        }

        // Eliminate below
        for (int i = k + 1; i < mSize; i++) {
            double factor = rA(i + 1, k + 1) / rA(k + 1, k + 1);
            for (int j = k; j < mSize; j++) {
                rA(i + 1, j + 1) -= factor * rA(k + 1, j + 1);
            }
            rb(i + 1) -= factor * rb(k + 1);
        }
    }

    // Back substitution
    for (int i = mSize - 1; i >= 0; i--) {
        solution(i + 1) = rb(i + 1);
        for (int j = i + 1; j < mSize; j++) {
            solution(i + 1) -= rA(i + 1, j + 1) * solution(j + 1);
        }
        solution(i + 1) /= rA(i + 1, i + 1);
    }

    return solution;
}
