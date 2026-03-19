#pragma once
#include <cstddef>

class FlatMatrix {
    int* _data = nullptr;
    size_t _size = 0;
    size_t _n = 0;
    size_t _m = 0;
public:
    FlatMatrix(size_t rows, size_t cols);

    FlatMatrix() = default;
    bool set(size_t rows, size_t cols);
    int* operator[](size_t i);
    int* operator[](size_t i) const;
    int& at(size_t rows, size_t cols) const;
    size_t getSize() const {return _size;};
    size_t getRows() const { return _n; }
    size_t getCols() const { return _m; }
    ~FlatMatrix();

};