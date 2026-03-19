#pragma once
#include "DynArray.h"

class Matrix {
    DynArray* _rows = nullptr;
    size_t _n = 0;
    size_t _m = 0;
    size_t _size = 0;
public:
    Matrix(size_t n, size_t m);
    bool set(size_t n, size_t m);
    Matrix() = default;
    DynArray& operator[](size_t i);
    const DynArray& operator[](size_t i) const;
    int& at(size_t row, size_t col);
    const int& at(size_t row, size_t col) const;
    size_t getSize() const {return _size;};
    size_t getRows() const { return _n; }
    size_t getCols() const { return _m; }
    ~Matrix();
    Matrix operator*(int scalar) const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    void resize(size_t newRows, size_t newCols);

};