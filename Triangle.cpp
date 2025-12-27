#include "../include/Triangle.h"
#include <cmath>
#include <stdexcept>

Triangle::Triangle() : vertices{Point(), Point(), Point()} {}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) 
    : vertices{p1, p2, p3} {}


Triangle::Triangle(const Triangle& other) {
    for (int i = 0; i < 3; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Point Triangle::center() const {
    double cx = (vertices[0].x + vertices[1].x + vertices[2].x) / 3.0;
    double cy = (vertices[0].y + vertices[1].y + vertices[2].y) / 3.0;
    return Point(cx, cy);
}

double Triangle::area() const {
    double a = vertices[0].x * (vertices[1].y - vertices[2].y);
    double b = vertices[1].x * (vertices[2].y - vertices[0].y);
    double c = vertices[2].x * (vertices[0].y - vertices[1].y);
    return std::abs(a + b + c) / 2.0;
}

void Triangle::print(std::ostream& os) const {
    for (int i = 0; i < 3; ++i) {
        os << vertices[i].x << " " << vertices[i].y;
        if (i < 2) os << " ";
    }
}

void Triangle::read(std::istream& is) {
    for (int i = 0; i < 3; ++i) {
        if (!(is >> vertices[i].x >> vertices[i].y)) {
            throw std::runtime_error("Invalid input for Triangle");
        }
    }
}

Triangle* Triangle::clone() const {
    return new Triangle(*this);
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        for (int i = 0; i < 3; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 3; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (!otherTriangle) return false;
    
    for (int i = 0; i < 3; ++i) {
        if (!(vertices[i] == otherTriangle->vertices[i])) {
            return false;
        }
    }
    return true;
}