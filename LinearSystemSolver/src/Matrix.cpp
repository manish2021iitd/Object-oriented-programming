#include "Matrix.hpp"
#include <cassert>
#include <iostream>

Matrix::Matrix() : mData(nullptr), mNumRows(0), mNumCols(0) {}

Matrix::Matrix(int numRows, int numCols) : mNumRows(numRows), mNumCols(numCols) {
    assert(numRows > 0 && numCols > 0);
    mData = new double*[numRows];
    for (int i = 0; i < numRows; ++i) {
        mData[i] = new double[numCols];
        for (int j = 0; j < numCols; ++j) {
            mData[i][j] = 0.0;  // Initialize matrix elements to 0
        }
    }
}

Matrix::Matrix(const Matrix& otherMatrix) : mNumRows(otherMatrix.mNumRows), mNumCols(otherMatrix.mNumCols) {
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j) {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < mNumRows; ++i) {
        delete[] mData[i];
    }
    delete[] mData;
}

int Matrix::GetnumRows() const {
    return mNumRows;
}

int Matrix::GetnumCols() const {
    return mNumCols;
}

double& Matrix::operator()(int i, int j) {
    assert(i >= 1 && i <= mNumRows);
    assert(j >= 1 && j <= mNumCols);
    return mData[i - 1][j - 1];
}

Matrix& Matrix::operator=(const Matrix& otherMatrix) {
    if (this != &otherMatrix) {
        for (int i = 0; i < mNumRows; ++i) {
            delete[] mData[i];
        }
        delete[] mData;

        mNumRows = otherMatrix.mNumRows;
        mNumCols = otherMatrix.mNumCols;

        mData = new double*[mNumRows];
        for (int i = 0; i < mNumRows; ++i) {
            mData[i] = new double[mNumCols];
            for (int j = 0; j < mNumCols; ++j) {
                mData[i][j] = otherMatrix.mData[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator+() const {
    return *this;
}

Matrix Matrix::operator-() const {
    Matrix result(*this);
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < mNumCols; ++j) {
            result.mData[i][j] = -result.mData[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator+(const Matrix& otherMatrix) const {
    assert(mNumRows == otherMatrix.mNumRows && mNumCols == otherMatrix.mNumCols);
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < mNumCols; ++j) {
            result.mData[i][j] = mData[i][j] + otherMatrix.mData[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& otherMatrix) const {
    assert(mNumRows == otherMatrix.mNumRows && mNumCols == otherMatrix.mNumCols);
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < mNumCols; ++j) {
            result.mData[i][j] = mData[i][j] - otherMatrix.mData[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& otherMatrix) const {
    assert(mNumCols == otherMatrix.mNumRows);
    Matrix result(mNumRows, otherMatrix.mNumCols);
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < otherMatrix.mNumCols; ++j) {
            result.mData[i][j] = 0.0;
            for (int k = 0; k < mNumCols; ++k) {
                result.mData[i][j] += mData[i][k] * otherMatrix.mData[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(*this);
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < mNumCols; ++j) {
            result.mData[i][j] *= scalar;
        }
    }
    return result;
}

Matrix operator*(double scalar, const Matrix& matrix) {
    return matrix * scalar;
}

double Matrix::determinant() const {
    assert(mNumRows == mNumCols);  // Ensure square matrix
    if (mNumRows == 1) return mData[0][0];
    if (mNumRows == 2) return mData[0][0] * mData[1][1] - mData[0][1] * mData[1][0];

    double det = 0.0;
    for (int j = 0; j < mNumCols; ++j) {
        Matrix subMatrix(mNumRows - 1, mNumCols - 1);
        for (int row = 1; row < mNumRows; ++row) {
            for (int col = 0; col < mNumCols; ++col) {
                if (col < j) {
                    subMatrix(row - 1, col) = mData[row][col];
                } else if (col > j) {
                    subMatrix(row - 1, col - 1) = mData[row][col];
                }
            }
        }
        det += mData[0][j] * ((j % 2 == 0) ? 1 : -1) * subMatrix.determinant();
    }
    return det;
}
