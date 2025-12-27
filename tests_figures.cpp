#include <gtest/gtest.h>
#include <sstream>
#include <cmath>
#include "../include/Figure.h"
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Octagon.h"
#include "../include/Array.h"

class TriangleTest : public ::testing::Test {
protected:
    void SetUp() override {
        triangle1 = new Triangle(Point(0, 0), Point(1, 0), Point(0, 1));
        triangle2 = new Triangle(Point(0, 0), Point(3, 0), Point(0, 3));
    }

    void TearDown() override {
        delete triangle1;
        delete triangle2;
    }

    Triangle* triangle1;
    Triangle* triangle2;
};

class SquareTest : public ::testing::Test {
protected:
    void SetUp() override {
        square1 = new Square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
        square2 = new Square(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    }

    void TearDown() override {
        delete square1;
        delete square2;
    }

    Square* square1;
    Square* square2;
};

class OctagonTest : public ::testing::Test {
protected:
    void SetUp() override {
        octagon1 = new Octagon(Point(0, 0), 1.0);
        octagon2 = new Octagon(Point(2, 3), 1.0);
    }

    void TearDown() override {
        delete octagon1;
        delete octagon2;
    }

    Octagon* octagon1;
    Octagon* octagon2;
};

class ArrayTest : public ::testing::Test {
protected:
    void SetUp() override {
        array = new Array();
        triangle = new Triangle(Point(0, 0), Point(1, 0), Point(0, 1));
        square = new Square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    }

    void TearDown() override {
        delete array;
    }

    Array* array;
    Triangle* triangle;
    Square* square;
};

TEST_F(TriangleTest, ConstructorAndArea) {
    EXPECT_NEAR(triangle1->area(), 0.5, 1e-9);
    EXPECT_NEAR(triangle2->area(), 4.5, 1e-9);
}

TEST_F(TriangleTest, CenterCalculation) {
    Point center1 = triangle1->center();
    Point center2 = triangle2->center();
    
    EXPECT_NEAR(center1.x, 1.0/3.0, 1e-9);
    EXPECT_NEAR(center1.y, 1.0/3.0, 1e-9);
    EXPECT_NEAR(center2.x, 1.0, 1e-9);
    EXPECT_NEAR(center2.y, 1.0, 1e-9);
}

TEST_F(TriangleTest, CopyConstructor) {
    Triangle copy(*triangle1);
    EXPECT_TRUE(*triangle1 == copy);
}

TEST_F(TriangleTest, CopyAssignment) {
    Triangle copy;
    copy = *triangle1;
    EXPECT_TRUE(*triangle1 == copy);
}

TEST_F(TriangleTest, MoveConstructor) {
    Triangle original(Point(0, 0), Point(1, 0), Point(0, 1));
    double original_area = original.area();
    
    Triangle moved(std::move(original));
    EXPECT_NEAR(moved.area(), original_area, 1e-9);
}

TEST_F(TriangleTest, MoveAssignment) {
    Triangle original(Point(0, 0), Point(1, 0), Point(0, 1));
    double original_area = original.area();
    
    Triangle moved;
    moved = std::move(original);
    EXPECT_NEAR(moved.area(), original_area, 1e-9);
}

TEST_F(TriangleTest, EqualityOperator) {
    Triangle same1(Point(0, 0), Point(1, 0), Point(0, 1));
    Triangle same2(Point(0, 0), Point(1, 0), Point(0, 1));
    Triangle different(Point(0, 0), Point(2, 0), Point(0, 2));
    
    EXPECT_TRUE(same1 == same2);
    EXPECT_FALSE(same1 == different);
}

TEST_F(TriangleTest, DoubleConversion) {
    double area = static_cast<double>(*triangle1);
    EXPECT_NEAR(area, 0.5, 1e-9);
}

TEST_F(SquareTest, ConstructorAndArea) {
    EXPECT_NEAR(square1->area(), 1.0, 1e-9);
    EXPECT_NEAR(square2->area(), 4.0, 1e-9);
}

TEST_F(SquareTest, CenterCalculation) {
    Point center1 = square1->center();
    Point center2 = square2->center();
    
    EXPECT_NEAR(center1.x, 0.5, 1e-9);
    EXPECT_NEAR(center1.y, 0.5, 1e-9);
    EXPECT_NEAR(center2.x, 1.0, 1e-9);
    EXPECT_NEAR(center2.y, 1.0, 1e-9);
}

TEST_F(SquareTest, CopyConstructor) {
    Square copy(*square1);
    EXPECT_TRUE(*square1 == copy);
}

TEST_F(SquareTest, CopyAssignment) {
    Square copy;
    copy = *square1;
    EXPECT_TRUE(*square1 == copy);
}

TEST_F(SquareTest, MoveConstructor) {
    Square original(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    double original_area = original.area();
    
    Square moved(std::move(original));
    EXPECT_NEAR(moved.area(), original_area, 1e-9);
}

TEST_F(SquareTest, MoveAssignment) {
    Square original(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    double original_area = original.area();
    
    Square moved;
    moved = std::move(original);
    EXPECT_NEAR(moved.area(), original_area, 1e-9);
}

TEST_F(SquareTest, EqualityOperator) {
    Square same1(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    Square same2(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    Square different(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    
    EXPECT_TRUE(same1 == same2);
    EXPECT_FALSE(same1 == different);
}

TEST_F(SquareTest, DoubleConversion) {
    double area = static_cast<double>(*square1);
    EXPECT_NEAR(area, 1.0, 1e-9);
}

TEST_F(OctagonTest, ConstructorAndArea) {
    double area1 = octagon1->area();
    double area2 = octagon2->area();
    
    EXPECT_GT(area1, 0);
    EXPECT_GT(area2, 0);
    EXPECT_NEAR(area1, area2, 1e-9);
}

TEST_F(OctagonTest, CenterCalculation) {
    Point center1 = octagon1->center();
    Point center2 = octagon2->center();
    
    EXPECT_NEAR(center1.x, 0.0, 1e-9);
    EXPECT_NEAR(center1.y, 0.0, 1e-9);
    EXPECT_NEAR(center2.x, 2.0, 1e-9);
    EXPECT_NEAR(center2.y, 3.0, 1e-9);
}

TEST_F(OctagonTest, CopyConstructor) {
    Octagon copy(*octagon1);
    EXPECT_TRUE(*octagon1 == copy);
}

TEST_F(OctagonTest, CopyAssignment) {
    Octagon copy;
    copy = *octagon1;
    EXPECT_TRUE(*octagon1 == copy);
}

TEST_F(OctagonTest, MoveConstructor) {
    Octagon original(Point(0, 0), 1.0);
    double original_area = original.area();
    
    Octagon moved(std::move(original));
    EXPECT_NEAR(moved.area(), original_area, 1e-9);
}

TEST_F(OctagonTest, MoveAssignment) {
    Octagon original(Point(0, 0), 1.0);
    double original_area = original.area();
    
    Octagon moved;
    moved = std::move(original);
    EXPECT_NEAR(moved.area(), original_area, 1e-9);
}

TEST_F(OctagonTest, EqualityOperator) {
    Octagon same1(Point(0, 0), 1.0);
    Octagon same2(Point(0, 0), 1.0);
    Octagon different(Point(1, 1), 1.0);
    
    EXPECT_TRUE(same1 == same2);
    EXPECT_FALSE(same1 == different);
}

TEST_F(OctagonTest, DoubleConversion) {
    double area = static_cast<double>(*octagon1);
    EXPECT_GT(area, 0);
}

TEST_F(ArrayTest, AddAndSize) {
    EXPECT_EQ(array->size(), 0);
    
    array->add(triangle);
    EXPECT_EQ(array->size(), 1);
    
    array->add(square);
    EXPECT_EQ(array->size(), 2);
}

TEST_F(ArrayTest, RemoveFigures) {
    array->add(triangle);
    array->add(square);
    
    EXPECT_EQ(array->size(), 2);
    array->remove(0);
    EXPECT_EQ(array->size(), 1);
    array->remove(0);
    EXPECT_EQ(array->size(), 0);
}

TEST_F(ArrayTest, TotalAreaCalculation) {
    array->add(triangle);
    array->add(square);
    
    double total_area = array->totalArea();
    EXPECT_NEAR(total_area, 1.5, 1e-9);
}

TEST_F(ArrayTest, CopyConstructor) {
    array->add(triangle);
    array->add(square);
    
    Array copy(*array);
    EXPECT_EQ(array->size(), copy.size());
    EXPECT_NEAR(array->totalArea(), copy.totalArea(), 1e-9);
}

TEST_F(ArrayTest, CopyAssignment) {
    array->add(triangle);
    array->add(square);
    
    Array copy;
    copy = *array;
    EXPECT_EQ(array->size(), copy.size());
    EXPECT_NEAR(array->totalArea(), copy.totalArea(), 1e-9);
}

TEST_F(ArrayTest, MoveConstructor) {
    array->add(triangle);
    array->add(square);
    double original_area = array->totalArea();
    size_t original_size = array->size();
    
    Array moved(std::move(*array));
    EXPECT_EQ(moved.size(), original_size);
    EXPECT_NEAR(moved.totalArea(), original_area, 1e-9);
}

TEST_F(ArrayTest, MoveAssignment) {
    array->add(triangle);
    array->add(square);
    double original_area = array->totalArea();
    size_t original_size = array->size();
    
    Array moved;
    moved = std::move(*array);
    EXPECT_EQ(moved.size(), original_size);
    EXPECT_NEAR(moved.totalArea(), original_area, 1e-9);
}

TEST_F(ArrayTest, IndexOperator) {
    array->add(triangle);
    array->add(square);
    
    Figure* fig1 = (*array)[0];
    Figure* fig2 = (*array)[1];
    
    EXPECT_NEAR(fig1->area(), 0.5, 1e-9);
    EXPECT_NEAR(fig2->area(), 1.0, 1e-9);
}

class IOTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(IOTest, TriangleInputOutput) {
    Triangle original(Point(0, 0), Point(1, 0), Point(0, 1));
    
    std::stringstream ss;
    ss << original;
    
    Triangle deserialized;
    ss >> deserialized;
    
    EXPECT_TRUE(original == deserialized);
}

TEST_F(IOTest, SquareInputOutput) {
    Square original(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    
    std::stringstream ss;
    ss << original;
    
    Square deserialized;
    ss >> deserialized;
    
    EXPECT_TRUE(original == deserialized);
}

class PolymorphismTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(PolymorphismTest, FigurePointerOperations) {
    Triangle triangle(Point(0, 0), Point(1, 0), Point(0, 1));
    Square square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    
    Figure* fig1 = &triangle;
    Figure* fig2 = &square;
    
    EXPECT_NEAR(fig1->area(), 0.5, 1e-9);
    EXPECT_NEAR(fig2->area(), 1.0, 1e-9);
    
    Point center1 = fig1->center();
    Point center2 = fig2->center();
    
    EXPECT_NEAR(center1.x, 1.0/3.0, 1e-9);
    EXPECT_NEAR(center1.y, 1.0/3.0, 1e-9);
    EXPECT_NEAR(center2.x, 0.5, 1e-9);
    EXPECT_NEAR(center2.y, 0.5, 1e-9);
}

TEST_F(PolymorphismTest, CloneOperation) {
    Triangle triangle(Point(0, 0), Point(1, 0), Point(0, 1));
    Square square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    
    Figure* triangle_clone = triangle.clone();
    Figure* square_clone = square.clone();
    
    EXPECT_TRUE(triangle == *triangle_clone);
    EXPECT_TRUE(square == *square_clone);
    
    delete triangle_clone;
    delete square_clone;
}

class IntegrationTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(IntegrationTest, CompleteWorkflow) {
    Array figures;
    
    figures.add(new Triangle(Point(0, 0), Point(1, 0), Point(0, 1)));
    figures.add(new Square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)));
    figures.add(new Octagon(Point(0, 0), 1.0));
    
    EXPECT_EQ(figures.size(), 3);
    
    double total_area = figures.totalArea();
    EXPECT_GT(total_area, 1.5);
    
    for (size_t i = 0; i < figures.size(); ++i) {
        Figure* figure = figures[i];
        Point center = figure->center();
        double area = figure->area();
        
        EXPECT_GT(area, 0);
        EXPECT_FALSE(std::isnan(center.x));
        EXPECT_FALSE(std::isnan(center.y));
    }
    
    figures.remove(1);
    EXPECT_EQ(figures.size(), 2);
    
    double new_total_area = figures.totalArea();
    EXPECT_LT(new_total_area, total_area);
}

class EdgeCaseTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(EdgeCaseTest, ZeroAreaTriangle) {
    Triangle triangle(Point(0, 0), Point(0, 0), Point(0, 0));
    EXPECT_NEAR(triangle.area(), 0.0, 1e-9);
}

TEST_F(EdgeCaseTest, SelfAssignment) {
    Triangle triangle(Point(0, 0), Point(1, 0), Point(0, 1));
    triangle = triangle;
    EXPECT_NEAR(triangle.area(), 0.5, 1e-9);
    
    Square square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));
    square = square;
    EXPECT_NEAR(square.area(), 1.0, 1e-9);
}

TEST_F(EdgeCaseTest, EmptyArrayOperations) {
    Array empty_array;
    EXPECT_EQ(empty_array.size(), 0);
    EXPECT_NEAR(empty_array.totalArea(), 0.0, 1e-9);
    
    EXPECT_NO_THROW({
        empty_array.remove(0);
    });
}