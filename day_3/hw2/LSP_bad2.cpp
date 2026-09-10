#include <iostream>

class Rectangle
{
protected:
    int width;
    int height;
public:
    virtual void setWidth(int width)
    {
        this->width = width;
    }
    virtual void setHeight(int height)
    {
        this->height = height;
    }
    int getArea()
    {
        return width * height;
    }
    virtual ~Rectangle() {}
};

class Square : public Rectangle
{
public:
    void setWidth(int width) override
    {
        this->width = width;
        this->height = width;
    }

    void setHeight(int height) override
    {
        this->width = height;
        this->height = height;
    }
};

class AreaCalculator
{
public:
    void calculateArea(Rectangle& rectangle)
    {
        rectangle.setWidth(5);
        rectangle.setHeight(4);
        std::cout << "Area: " << rectangle.getArea() << std::endl;
    }
};

int main()
{
    Rectangle rectangle;
    AreaCalculator calculator;

    std::cout << "-- Rectangle --" << std::endl;
    calculator.calculateArea(rectangle); // Area: 20

    Square square;
    std::cout << "-- Square --" << std::endl;
    calculator.calculateArea(square);    // Area: 16 (LSP 위반)


    return 0;
}
