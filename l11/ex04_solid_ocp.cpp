#include <iostream>
#include <vector>

class Shape {
public:
    // Metoda pur virtuala, obliga clasele derivate sa o implementeze
    virtual double Area() const = 0; 
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    // Constructor pentru initializarea latimii si inaltimii
    Rectangle(double w, double h) : width(w), height(h) {}
    // Suprascrierea metodei Area specifica pentru dreptunghi
    double Area() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    // Constructor pentru initializarea razei
    Circle(double r) : radius(r) {}
    // Suprascrierea metodei Area specifica pentru cerc
    double Area() const override {
        const double PI = 3.1415926;
        return PI * radius * radius;
    }
};

void PrintTotalArea(const std::vector<Shape*>& shapes) {
    double totalArea = 0;
    for (const auto& shape : shapes) {
        // Calculul ariei totale prin adunarea ariilor individuale
        totalArea += shape->Area(); 
    }
    // Afisarea ariei totale
    std::cout << "Total Area: " << totalArea << std::endl; 
}

int main() 
{
    // Vector pentru stocarea pointerilor catre obiecte de tip Shape
    std::vector<Shape*> shapes;
    // Crearea si adaugarea formelor in vector
    shapes.push_back(new Rectangle(10, 20));
    shapes.push_back(new Circle(10));

    // Afisarea ariei totale a formelor stocate in vector
    PrintTotalArea(shapes);

    // Eliberarea memoriei
    for (auto& shape : shapes) {
        // Eliberarea memoriei pentru fiecare forma
        delete shape; 
    }
    // Redimensionarea vectorului la zero elemente
    shapes.clear(); 

    return 0;
}
