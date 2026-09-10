#include <iostream>
#include <memory>

class Shape
{
public:
    virtual int getArea() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
private:
    int width;
    int height;
public:
    Rectangle(int width, int height)
        : width(width), height(height) {}

    int getArea() override
    {
        return width * height;
    }
};

class Square : public Shape
{
private:
    int side;
public:
    Square(int side)
        : side(side) {}

    int getArea() override
    {
        return side * side;
    }
};

class AreaCalculator
{
public:
    void calculateArea(Shape& shape)
    {
        std::cout << "Area: " << shape.getArea() << std::endl;
    }
};

int main()
{
    AreaCalculator calculator;

    Rectangle rectangle(5, 4);
    calculator.calculateArea(rectangle); // Area: 20

    Square square(4);
    calculator.calculateArea(square);    // Area: 16 (정상 - Square의 정의대로 4x4)

    return 0;
}
