#include <iostream>
#include <vector>
#include <memory>

// Aplicatia respecta toate principiile SOLID

// Interfata ICommand - Command Pattern
class ICommand {
public:
    virtual void Execute() = 0;
    // Teoretic =0 dar nu fortez subclasele sa implementeze destructor daca nu au nevoie
    virtual ~ICommand() {}
};

// Comanda concreta
class Order {
public:
    void PrepareOrder(const std::string& orderDetails) {
        std::cout << "Preparing order: " << orderDetails << std::endl;
    }
};

class OrderCommand : public ICommand {
private:
    Order *order;
    std::string orderDetails;
public:
    OrderCommand(Order *order, const std::string& details) : order(order), orderDetails(details) {}
    void Execute() override {
        order->PrepareOrder(orderDetails);
    }
};

// Command Factory
class CommandFactory {
public:
    static std::unique_ptr<ICommand> CreateCommand(Order *order, const std::string& details) {
        return std::make_unique<OrderCommand>(order, details);
    }
};

// Observer Pattern
class Kitchen {
private:
    std::vector<std::unique_ptr<ICommand>> commands;
public:
    void AddOrder(ICommand *command) {
        commands.emplace_back(command);
    }
    void Notify() {
        for (auto& command : commands) {
            command->Execute();
        }
        commands.clear();
    }
};

// Functia main(), ilustrand Dependency Inversion si Factory Pattern
int main() 
{
    Kitchen kitchen;
    Order order;

    auto breakfastOrder = CommandFactory::CreateCommand(&order, "Breakfast");
    auto lunchOrder = CommandFactory::CreateCommand(&order, "Lunch");

    kitchen.AddOrder(breakfastOrder.get());
    kitchen.AddOrder(lunchOrder.get());

    kitchen.Notify();

    return 0;
}
