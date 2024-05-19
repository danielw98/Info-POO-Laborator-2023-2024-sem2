#include <iostream>

// Componenta abstracta
class Component {
public:
    virtual void Operation() = 0;
    virtual ~Component() {}
};

// Componenta concreta
class ConcreteComponent : public Component {
public:
    void Operation() override {
        std::cout << "ConcreteComponent operation." << std::endl;
    }
};

// Decoratorul abstract
class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* c) : component(c) {}
    void Operation() override {
        component->Operation();
    }
};

// Decorator concret
class ConcreteDecorator : public Decorator {
public:
    ConcreteDecorator(Component* c) : Decorator(c) {}
    void Operation() override {
        Decorator::Operation();
        AddedBehavior();
    }
    void AddedBehavior() {
        std::cout << "ConcreteDecorator added behavior." << std::endl;
    }
};

int main() {
    Component* simple = new ConcreteComponent();
    Component* decorated = new ConcreteDecorator(simple);
    decorated->Operation();
    delete simple;
    delete decorated;
    return 0;
}
