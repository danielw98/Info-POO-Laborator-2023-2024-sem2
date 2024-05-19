#include <iostream>
#include <memory>

class Product {
public:
    virtual void Operate() = 0;
    virtual ~Product() {}
};

class ConcreteProductA : public Product {
public:
    void Operate() override {
        std::cout << "Operating ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void Operate() override {
        std::cout << "Operating ConcreteProductB" << std::endl;
    }
};

class Creator {
public:
    virtual std::unique_ptr<Product> FactoryMethod() = 0;
    virtual ~Creator() {}
};

class ConcreteCreatorA : public Creator {
public:
    std::unique_ptr<Product> FactoryMethod() override {
        return std::make_unique<ConcreteProductA>();
    }
};

class ConcreteCreatorB : public Creator {
public:
    std::unique_ptr<Product> FactoryMethod() override {
        return std::make_unique<ConcreteProductB>();
    }
};

int main() {
    std::unique_ptr<Creator> creatorA = std::make_unique<ConcreteCreatorA>();
    std::unique_ptr<Product> productA = creatorA->FactoryMethod();
    productA->Operate();

    std::unique_ptr<Creator> creatorB = std::make_unique<ConcreteCreatorB>();
    std::unique_ptr<Product> productB = creatorB->FactoryMethod();
    productB->Operate();
    return 0;
}
