#pragma once

#include "Figure.h"

class Triangle : public Figure {
private:
    Point vertices[3];
    
public:
    Triangle();
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    Triangle(const Triangle& other);
    
    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Triangle* clone() const override;
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    bool operator==(const Figure& other) const override;
};
