#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix(size_t n, size_t m) : Matrix(){
    if (!(set(n, m))) {
        throw std::invalid_argument("Invalid argument");
    }


}

bool Matrix::set(size_t n, size_t m) {
    if (n * m < 0) {
        return false;
    }

    _n = n;
    _m = m;
    _size = n*m;
    _rows = new DynArray[_n];

    for (size_t i = 0; i < _n; ++i) {
        _rows[i].set(_m);
    }
    return true;
}

DynArray& Matrix::operator[](size_t i) {
    return _rows[i];
}

const DynArray& Matrix::operator[](size_t i) const {
    return _rows[i];
}
int& Matrix::at(size_t row, size_t col) {
    if (row >= _n || col >= _m) {
        throw std::out_of_range("Index is out of range");
    }

    return _rows[row].at(col);
}

const int& Matrix::at(size_t row, size_t col) const {
    if (row >= _n || col >= _m) {
        throw std::out_of_range("Index is out of range");
    }
    return _rows[row].at(col);
}

Matrix::~Matrix() {
    delete[] _rows;
}

Matrix Matrix::operator*(int scalar) const {
    Matrix resultDim(_n, _m);
    for (size_t i = 0; i < _n; i++) {
        for (size_t j = 0; j < _m; j++) {
            resultDim[i][j] = _rows[i][j] * scalar;
        }
    }
    return resultDim;
}
Matrix Matrix::operator+(const Matrix& other) const {
    if (_n != other._n || _m != other._m) throw std::invalid_argument("Invalid dim");
    Matrix result(_n, _m);
    for (size_t i = 0; i < _n; ++i) {
        for (size_t j = 0; j < _m; ++j) {
            result[i][j] = _rows[i][j] + other[i][j];
        }
    }
    return result;
}

// Matrix Subtraction
Matrix Matrix::operator-(const Matrix& other) const {
    if (_n != other._n || _m != other._m) throw std::invalid_argument("Invalid dim");
    Matrix result(_n, _m);
    for (size_t i = 0; i < _n; ++i) {
        for (size_t j = 0; j < _m; ++j) {
            result[i][j] = _rows[i][j] - other[i][j];
        }
    }
    return result;
}

// Matrix Multiplication
Matrix Matrix::operator*(const Matrix& other) const {
    if (_m != other._n) throw std::invalid_argument("Invalid dim");
    Matrix result(_n, other._m);

    for (size_t i = 0; i < _n; ++i) {
        for (size_t j = 0; j < other._m; ++j) {
            int sum = 0;
            for (size_t k = 0; k < _m; ++k) {
                sum += _rows[i][k] * other[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}


void Matrix::resize(size_t newRows, size_t newCols) {
    auto* newRowsArr = new DynArray[newRows];


    for (size_t i = 0; i < newRows; ++i) {
        newRowsArr[i].resize(newCols);
    }

    size_t minRows = (newRows < _n) ? newRows : _n;
    size_t minCols = (newCols < _m) ? newCols : _m;


    for (size_t i = 0; i < minRows; ++i) {
        for (size_t j = 0; j < minCols; ++j) {
            newRowsArr[i][j] = _rows[i][j];
        }
    }

    delete[] _rows;
    _rows = newRowsArr;
    _n = newRows;
    _m = newCols;
    _size = newRows * newCols;
}