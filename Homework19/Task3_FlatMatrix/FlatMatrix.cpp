#include "FlatMatrix.h"
#include <stdexcept>
#include <algorithm>

bool FlatMatrix::set(size_t rows, size_t cols) {

    if (rows == 0 || cols == 0) {
        return false;
    }
    _n = rows;
    _m = cols;
    _size = rows * cols;


    delete[] _data;
    _data = new int[_size]{0};
    return true;
}

FlatMatrix::FlatMatrix(size_t rows, size_t cols) {
    if (!set(rows, cols)) {
        throw std::invalid_argument("Invalid arguments");
    }
}


FlatMatrix::FlatMatrix(const FlatMatrix& other) : _n(other._n), _m(other._m), _size(other._size) {
    if (_size > 0) {
        _data = new int[_size];
        std::copy(other._data, other._data + _size, _data);
    }
}


FlatMatrix& FlatMatrix::operator=(const FlatMatrix& other) {
    if (this != &other) {
        delete[] _data;
        _n = other._n;
        _m = other._m;
        _size = other._size;

        if (_size > 0) {
            _data = new int[_size];
            std::copy(other._data, other._data + _size, _data);
        } else {
            _data = nullptr;
        }
    }
    return *this;
}

int* FlatMatrix::operator[](size_t i) {
    return _data + (i * _m);
}


const int* FlatMatrix::operator[](size_t i) const {
    return _data + (i * _m);
}

int& FlatMatrix::at(size_t rows, size_t cols) const {
    if (rows >= _n || cols >= _m) {
        throw std::out_of_range("Index is out of range");
    }
    return _data[rows * _m + cols];
}

FlatMatrix FlatMatrix::operator*(int scalar) const {
    FlatMatrix result(_n, _m);
    for (size_t i = 0; i < _size; ++i) {
        result._data[i] = _data[i] * scalar;
    }
    return result;
}

FlatMatrix FlatMatrix::operator+(const FlatMatrix& other) const {
    if (_n != other._n || _m != other._m) throw std::invalid_argument("Invalid dim");
    FlatMatrix result(_n, _m);
    for (size_t i = 0; i < _size; ++i) {
        result._data[i] = _data[i] + other._data[i];
    }
    return result;
}

FlatMatrix FlatMatrix::operator-(const FlatMatrix& other) const {
    if (_n != other._n || _m != other._m) throw std::invalid_argument("Invalid dim");
    FlatMatrix result(_n, _m);
    for (size_t i = 0; i < _size; ++i) {
        result._data[i] = _data[i] - other._data[i];
    }
    return result;
}

FlatMatrix FlatMatrix::operator*(const FlatMatrix& other) const {
    if (_m != other._n) throw std::invalid_argument("Invalid dim");
    FlatMatrix result(_n, other._m);

    for (size_t i = 0; i < _n; ++i) {
        for (size_t j = 0; j < other._m; ++j) {
            int sum = 0;
            for (size_t k = 0; k < _m; ++k) {

                sum += (*this)[i][k] * other[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

void FlatMatrix::resize(size_t newRows, size_t newCols) {
    FlatMatrix newMat(newRows, newCols);

    size_t minRows = (newRows < _n) ? newRows : _n;
    size_t minCols = (newCols < _m) ? newCols : _m;

    for (size_t i = 0; i < minRows; ++i) {
        for (size_t j = 0; j < minCols; ++j) {
            newMat[i][j] = (*this)[i][j];
        }
    }

    *this = newMat;
}

FlatMatrix::~FlatMatrix() {
    delete[] _data;
}