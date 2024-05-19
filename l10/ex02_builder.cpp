#include <iostream>
#include <string>

// Produsul final
class Car {
    std::string make;
    std::string model;
    int horsepower;
    std::string interior;

public:
    void SetMake(const std::string& make) { this->make = make; }
    void SetModel(const std::string& model) { this->model = model; }
    void SetHorsepower(int horsepower) { this->horsepower = horsepower; }
    void SetInterior(const std::string& interior) { this->interior = interior; }

    void Display() const {
        std::cout << "Car: " << make << " " << model
                  << " with " << horsepower << " horsepower and "
                  << interior << " interior." << std::endl;
    }
};

// Abstract Builder
class CarBuilder {
protected:
    Car car;

public:
    virtual ~CarBuilder() {}
    Car GetCar() { return car; }

    virtual void BuildMake() = 0;
    virtual void BuildModel() = 0;
    virtual void BuildHorsepower() = 0;
    virtual void BuildInterior() = 0;
};

// Concrete Builder
class SportsCarBuilder : public CarBuilder {
public:
    void BuildMake() override { car.SetMake("Ferrari"); }
    void BuildModel() override { car.SetModel("488 Spider"); }
    void BuildHorsepower() override { car.SetHorsepower(670); }
    void BuildInterior() override { car.SetInterior("Leather"); }
};

// Director
class Director {
    CarBuilder* builder;

public:
    void SetBuilder(CarBuilder* b) { builder = b; }

    Car Construct() {
        builder->BuildMake();
        builder->BuildModel();
        builder->BuildHorsepower();
        builder->BuildInterior();
        return builder->GetCar();
    }
};

int main() {
    Director director;
    SportsCarBuilder builder;
    director.SetBuilder(&builder);

    Car myDreamCar = director.Construct();
    myDreamCar.Display();
}