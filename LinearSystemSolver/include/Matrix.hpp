#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
private:
    double** mData;  // Data stored in matrix
    int mNumRows;    // Number of rows in matrix
    int mNumCols;    // Number of columns in matrix

public:
    Matrix();  // Default constructor
    Matrix(const Matrix& otherMatrix);  // Copy constructor
    Matrix(int numRows, int numCols);   // Constructor with size
    ~Matrix();  // Destructor

    int GetnumRows() const;  // Method to get number of rows
    int GetnumCols() const;  // Method to get number of columns

    double& operator()(int i, int j);  // Overloading round brackets

    Matrix& operator=(const Matrix& otherMatrix);  // Overloading assignment operator

    // Determinant function
    double determinant() const;

    // Unary and binary operators
    Matrix operator+() const;
    Matrix operator-() const;
    Matrix operator+(const Matrix& otherMatrix) const;
    Matrix operator-(const Matrix& otherMatrix) const;
    Matrix operator*(const Matrix& otherMatrix) const;
    Matrix operator*(double scalar) const;
    friend Matrix operator*(double scalar, const Matrix& matrix);
};

#endif // MATRIX_HPP
