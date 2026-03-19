#include "DynArray.h"
#include <stdexcept>


DynArray::DynArray(const size_t size) : DynArray() {
    if (!(set(size))) {
        throw std::invalid_argument("Invalid argument!");
    }
}

bool DynArray::set(const size_t size) {
    if (size > 0) {
        _size = size;
        _data = new int[size];
        return true;
    }
    return false;

}
int& DynArray::operator[](size_t i) {
    return _data[i];
}

int& DynArray::operator[](size_t i) const {
    return _data[i];
}
int& DynArray::at(size_t i) const {
    if (i >= _size) {
        throw std::out_of_range("Index is out of range");
    }
    return _data[i];
}
DynArray::DynArray(const DynArray& other) : _size(other._size) {
    if (_size > 0) {
        _data = new int[_size];
        std::copy(other._data, other._data + _size, _data);
    } else {
        _data = nullptr;
    }
}
DynArray& DynArray::operator=(const DynArray& other) {
    if (this != &other) {
        delete[] _data;
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

void DynArray::resize(size_t newSize) {
    if (newSize == _size) return;


    int* newData = newSize > 0 ? new int[newSize]{0} : nullptr;

    if (_data && newData) {

        size_t elementsToCopy = (newSize < _size) ? newSize : _size;
        std::copy(_data, _data + elementsToCopy, newData);
    }

    delete[] _data; \
    _data = newData;
    _size = newSize;
}
DynArray::~DynArray() {
    delete[] _data;
}
