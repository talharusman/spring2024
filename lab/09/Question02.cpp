#include <iostream>
using namespace std;
#include <cmath>

class Shape
{
public:
    Shape() {}
    virtual float area() const
    {
        return 0;
    }
    virtual float perimeter() const
    {
        return 0;
    }
    virtual void displayProperties() const
    {
        // Display properties specific to each shape
    }
};

class Rectangle : public Shape
{
private:
    int length;
    int width;

public:
    Rectangle(int length, int width) : length(length), width(width) {}
    float area() const override
    {
        return length * width;
    }
    float perimeter() const override
    {
        return 2 * (length + width);
    }

    void displayProperties() const override
    {
        cout << "Area of Rectangul: " << area() << endl;
        cout << "Perimeter of Rectangle: " << perimeter() << endl;
    }
};

class Circle : public Shape
{
    float radius;
    float pi = 3.14;

public:
    Circle(float radius) : radius(radius) {}
    float area() const override
    {
        return pi * radius * radius;
    }
    float perimeter() const override
    {
        return 2 * pi * radius;
    }
    void displayProperties() const override
    {
        cout << "Area of Circle: " << area() << endl;
        cout << "Perimeter of Circle: " << perimeter() << endl;
    }
};

class Square : public Shape
{
    int length;

public:
    Square(int length) : length(length) {}
    float area() const override
    {
        return length * length;
    }
    float perimeter() const override
    {
        return 4 * length;
    }
    void displayProperties() const override
    {
        cout << "Area of Square: " << area() << endl;
        cout << "Perimeter of Squear: " << perimeter() << endl;
    }
};

class Triangle : public Shape
{
    double base, height, perpendculer;

public:
    Triangle(double base, double height, double perpendculer) : base(base), height(height), perpendculer(perpendculer) {}

    float perimeter() const override
    {
        return base + height + perpendculer;
    }

    float area() const override
    {
        return sqrt(perimeter() * (perimeter() - base) * (perimeter() - height) * (perimeter() - perpendculer));
    }

    void displayProperties() const override
    {
        cout << "Area of Triangle: " << area() << endl;
        cout << "Perimeter of Triangle: " << perimeter() << endl;
    }
};

class EquilateralTriangle : public Triangle
{
    double B;

public:
    EquilateralTriangle(double B) : Triangle(B, B, B), B(B) {}

    float perimeter() const override
    {
        return 3 * B;
    }
    float area() const override
    {
        return (sqrt(3) / 4) * B * B;
    }
    void displayProperties() const override
    {
        cout << "Area of Equilateral Triangle: " << area() << endl;
        cout << "Perimeter of Equilateral Triangle: " << perimeter() << endl;
    }
};
int main()
{
    // Create a base class pointer

    Shape *shapes; // Corrected the typo

    // Dynamically allocate objects of different shapes
    Rectangle rectangle(5, 3);
    Circle circle(4);
    Square square(6);
    EquilateralTriangle equilateralTriangle(7);

    // Assign the addresses of the objects to the base class pointer
    shapes = &rectangle;
    shapes->displayProperties();
    cout << "\n";

    shapes = &circle;
    shapes->displayProperties();
    cout << "\n";

    shapes = &square;
    shapes->displayProperties();
    cout << "\n";

    shapes = &equilateralTriangle;
    shapes->displayProperties();
    cout << "\n";

    return 0;
}
