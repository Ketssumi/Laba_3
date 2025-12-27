#pragma once

#include "Figure.h"

class Array {
private:
    Figure** figures;
    size_t capacity;
    size_t size_; 
    
    void resize(); 

public:
    Array();
    ~Array();
    
    void add(Figure* figure);
    void remove(size_t index);
    size_t size() const;
    Figure* operator[](size_t index) const;
    
    double totalArea() const;
    void printAll() const;
    void printCentersAndAreas() const;
    
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(Array&& other) noexcept;
};
