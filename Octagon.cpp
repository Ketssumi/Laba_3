#include "../include/Octagon.h"
#include <cmath>
#include <stdexcept>
#include <corecrt_math_defines.h>

Octagon::Octagon() {
    for (int i = 0; i < 8; ++i) {
        vertices[i] = Point();
    }
}

Octagon::Octagon(const Point& center, double radius) {
    for (int i = 0; i < 8; ++i) {
        double angle = 2.0 * M_PI * i / 8.0;
        vertices[i].x = center.x + radius * std::cos(angle);
        vertices[i].y = center.y + radius * std::sin(angle);
    }
}

Octagon::Octagon(const Octagon& other) {
    for (int i = 0; i < 8; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Point Octagon::center() const {
    double cx = 0, cy = 0;
    for (int i = 0; i < 8; ++i) {
        cx += vertices[i].x;
        cy += vertices[i].y;
    }
    return Point(cx / 8.0, cy / 8.0);
}

double Octagon::area() const {
    double area = 0;
    for (int i = 0; i < 8; ++i) {
        int j = (i + 1) % 8;
        area += vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

void Octagon::print(std::ostream& os) const {
    for (int i = 0; i < 8; ++i) {
        os << vertices[i].x << " " << vertices[i].y;
        if (i < 7) os << " ";
    }
}

void Octagon::read(std::istream& is) {
    for (int i = 0; i < 8; ++i) {
        if (!(is >> vertices[i].x >> vertices[i].y)) {
            throw std::runtime_error("Invalid input for Octagon");
        }
    }
}

Octagon* Octagon::clone() const {
    return new Octagon(*this);
}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        for (int i = 0; i < 8; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 8; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* otherOctagon = dynamic_cast<const Octagon*>(&other);
    if (!otherOctagon) return false;
    
    for (int i = 0; i < 8; ++i) {
        if (!(vertices[i] == otherOctagon->vertices[i])) {
            return false;
        }
    }
    return true;
}