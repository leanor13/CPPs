#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* _data;
    size_t _size;

public:
    Array();
    Array(size_t n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t size() const;
};

#include "Array.tpp"

#endif