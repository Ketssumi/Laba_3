#include "../include/Square.h"
#include <cmath>
#include <stdexcept>

Square::Square() : vertices{Point(), Point(), Point(), Point()} {}

Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : vertices{p1, p2, p3, p4} {}

Square::Square(const Square& other) {
    for (int i = 0; i < 4; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Point Square::center() const {
    double cx = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) / 4.0;
    double cy = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) / 4.0;
    return Point(cx, cy);
}

double Square::area() const {
    double side1 = std::sqrt(std::pow(vertices[1].x - vertices[0].x, 2) + 
                           std::pow(vertices[1].y - vertices[0].y, 2));
    return side1 * side1;
}

void Square::print(std::ostream& os) const {
    for (int i = 0; i < 4; ++i) {
        os << vertices[i].x << " " << vertices[i].y;
        if (i < 3) os << " ";
    }
}

void Square::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        if (!(is >> vertices[i].x >> vertices[i].y)) {
            throw std::runtime_error("Invalid input for Square");
        }
    }
}

Square* Square::clone() const {
    return new Square(*this);
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool Square::operator==(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (!otherSquare) return false;
    
    for (int i = 0; i < 4; ++i) {
        if (!(vertices[i] == otherSquare->vertices[i])) {
            return false;
        }
    }
    return true;
}