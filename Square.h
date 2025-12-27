#pragma once

#include "Figure.h"

class Square : public Figure {
private:
    Point vertices[4];
    
public:
    Square();
    Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    Square(const Square& other);
    
    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Square* clone() const override;
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    bool operator==(const Figure& other) const override;
};