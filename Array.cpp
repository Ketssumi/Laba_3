#include "../include/Array.h"
#include <iostream>
#include <algorithm>

const size_t INITIAL_CAPACITY = 10;

Array::Array() : figures(nullptr), capacity(0), size_(0) {
    figures = new Figure*[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
}

Array::~Array() {
    for (size_t i = 0; i < size_; ++i) {
        delete figures[i];
    }
    delete[] figures;
}

void Array::resize() {
    size_t new_capacity = capacity * 2;
    Figure** new_figures = new Figure*[new_capacity];
    
    for (size_t i = 0; i < size_; ++i) {
        new_figures[i] = figures[i];
    }
    
    delete[] figures;
    figures = new_figures;
    capacity = new_capacity;
}

void Array::add(Figure* figure) {
    if (size_ >= capacity) {
        resize();
    }
    figures[size_] = figure;
    size_++;
}

void Array::remove(size_t index) {
    if (index >= size_) {
        return;
    }
    
    delete figures[index];
    
    for (size_t i = index; i < size_ - 1; ++i) {
        figures[i] = figures[i + 1];
    }
    
    size_--;
    figures[size_] = nullptr;
}

size_t Array::size() const {
    return size_;
}

Figure* Array::operator[](size_t index) const {
    if (index >= size_) {
        return nullptr;
    }
    return figures[index];
}

double Array::totalArea() const {
    double total = 0;
    for (size_t i = 0; i < size_; ++i) {
        total += figures[i]->area();
    }
    return total;
}

void Array::printAll() const {
    for (size_t i = 0; i < size_; ++i) {
        std::cout << "Figure " << i << ": " << *figures[i] << std::endl;
    }
}

void Array::printCentersAndAreas() const {
    for (size_t i = 0; i < size_; ++i) {
        Point center = figures[i]->center();
        double area = figures[i]->area();
        std::cout << "Figure " << i << ": Center(" << center.x << ", " << center.y 
                  << "), Area: " << area << std::endl;
    }
}

Array::Array(const Array& other) : figures(nullptr), capacity(0), size_(0) {
    figures = new Figure*[other.capacity];
    capacity = other.capacity;
    size_ = other.size_;
    
    for (size_t i = 0; i < size_; ++i) {
        figures[i] = other.figures[i]->clone();
    }
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        for (size_t i = 0; i < size_; ++i) {
            delete figures[i];
        }
        delete[] figures;
        
        figures = new Figure*[other.capacity];
        capacity = other.capacity;
        size_ = other.size_;
        
        for (size_t i = 0; i < size_; ++i) {
            figures[i] = other.figures[i]->clone();
        }
    }
    return *this;
}

Array::Array(Array&& other) noexcept 
    : figures(other.figures), capacity(other.capacity), size_(other.size_) {
    other.figures = nullptr;
    other.capacity = 0;
    other.size_ = 0;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < size_; ++i) {
            delete figures[i];
        }
        delete[] figures;
        
        figures = other.figures;
        capacity = other.capacity;
        size_ = other.size_;
        
        other.figures = nullptr;
        other.capacity = 0;
        other.size_ = 0;
    }
    return *this;
}