#include <iostream>
#include <utility>
#include <vector>

constexpr double PI = 3.1415926;

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

class Shape {
private:
    std::string culoare;
    std::pair<int, int> pozitie;
public:
    Shape(std::string culoare_="", int posX=-1, int posY=-1) : culoare{culoare_}, pozitie{std::make_pair(posX, posY)}{}
    virtual double GetArea(void) = 0;
    virtual double GetPerimeter(void) = 0;
    virtual std::string GetType(void) = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(std::string culoare_="", int posX=-1, int posY=-1, double radius_ = -1) 
        : Shape(culoare_, posX, posY), radius{radius_} {}
    double GetArea(void) override
    {
        return PI*radius*radius;
    }
    double GetPerimeter(void) override
    {
        return 2 * PI * radius;
    }
    std::string GetType(void) override
    {
        return "Circle";
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(std::string culoare_="", int posX=-1, int posY=-1, double width_ = -1, double height_ = -1) 
        : Shape(culoare_, posX, posY), width{width_}, height{height_} {}
    double GetArea(void) override
    {
        return width * height;
    }
    double GetPerimeter(void) override
    {
        return 2 * (width + height);
    }
    std::string GetType(void) override
    {
        return "Rectangle";
    }
};

int main()
{
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle("rosu", 100, 200, 10, 20));
    shapes.push_back(new Circle("verde", 200, 100, 3));
    
    for(Shape *shape : shapes)
    {
        std::cout << shape->GetType() << std::endl;
        std::cout << "Area: " << shape->GetArea() << std::endl;
        std::cout << "Perimeter: " << shape->GetPerimeter() << std::endl;
        std::cout << "----\n";
        delete shape;
    }
    return 0;
}