#include <iostream>

// Interfata tinta
class Target {
public:
    virtual void Request() const = 0;
};

// Clasa existenta cu o interfata diferita
class Adaptee {
public:
    void SpecificRequest() const {
        std::cout << "Specific request." << std::endl;
    }
};

// Adapterul
class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* a) : adaptee(a) {}
    void Request() const override {
        adaptee->SpecificRequest();
    }
};

int main() {
    Adaptee* adaptee = new Adaptee();
    Target* target = new Adapter(adaptee);
    target->Request();
    delete adaptee;
    delete target;
    return 0;
}
