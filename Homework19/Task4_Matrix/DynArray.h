#pragma once
#include <cstddef>

class DynArray {
    int* _data = nullptr;
    size_t _size = 0;
public:
    DynArray(size_t size);

    DynArray() = default;

    bool set(size_t size);
    int& operator[](size_t i) const;
    int& operator[](size_t i);
    int& at(size_t i) const;
    size_t getSize() const { return _size; }
    DynArray(const DynArray& other);
    DynArray& operator=(const DynArray& other);
    void resize(size_t newSize);
    ~DynArray();

};