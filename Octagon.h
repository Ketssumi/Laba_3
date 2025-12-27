#pragma once

#include "Figure.h"

class Octagon : public Figure {
private:
    Point vertices[8];
    
public:
    Octagon();
    Octagon(const Point& center, double radius);
    Octagon(const Octagon& other);
    
    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Octagon* clone() const override;
    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& other) noexcept;
    bool operator==(const Figure& other) const override;
};