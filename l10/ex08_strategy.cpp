#include <iostream>

class Strategy {
public:
    virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    void AlgorithmInterface() override {
        std::cout << "Implemented Algorithm A" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void AlgorithmInterface() override {
        std::cout << "Implemented Algorithm B" << std::endl;
    }
};

class Context {
    Strategy* strategy;
public:
    Context(Strategy* strategy) : strategy(strategy) {}
    void SetStrategy(Strategy* strategy) {
        this->strategy = strategy;
    }
    void ExecuteStrategy() {
        strategy->AlgorithmInterface();
    }
};

int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;
    Context context(&strategyA);
    context.ExecuteStrategy();
    context.SetStrategy(&strategyB);
    context.ExecuteStrategy();
    return 0;
}
