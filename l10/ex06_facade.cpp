#include <iostream>

class SubsystemA {
public:
    void OperationA() {
        std::cout << "Subsystem A operation." << std::endl;
    }
};

class SubsystemB {
public:
    void OperationB() {
        std::cout << "Subsystem B operation." << std::endl;
    }
};

class Facade {
private:
    SubsystemA* subsystemA;
    SubsystemB* subsystemB;

public:
    Facade() : subsystemA(new SubsystemA()), subsystemB(new SubsystemB()) {}
    ~Facade() {
        delete subsystemA;
        delete subsystemB;
    }
    void Operation() {
        subsystemA->OperationA();
        subsystemB->OperationB();
    }
};

int main() {
    Facade* facade = new Facade();
    facade->Operation();
    delete facade;
    return 0;
}
