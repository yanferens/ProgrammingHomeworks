#include "FlatMatrix.h"
#include <stdexcept>

bool FlatMatrix::set(size_t rows, size_t cols) {
    if (rows*cols < 0) {
        return false;
    }
    _n = rows;
    _m = cols;
    _size = rows*cols;
    _data = new int[rows * cols]{0};
    return true;

}

FlatMatrix::FlatMatrix(size_t rows, size_t cols) : FlatMatrix() {
    if (!set(rows, cols)) {
        throw std::invalid_argument("Invalid arguments");
    }
}

int* FlatMatrix::operator[](size_t i) {
    return _data + (i * _m);
}
int* FlatMatrix::operator[](size_t i) const {
    return _data + (i * _m);
}
int& FlatMatrix::at(size_t rows, size_t cols) const {
    if (rows >= _n || cols >= _m) {
        throw std::out_of_range("Index is out of range");
    }

    return _data[rows * _m + cols];
}

FlatMatrix::~FlatMatrix() {
    delete[] _data;
}

