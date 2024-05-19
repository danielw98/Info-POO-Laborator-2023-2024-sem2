#include <iostream>
#include <vector>

class Command {
public:
    virtual void Execute() = 0;
    virtual ~Command() {}
};

class Light {
public:
    void TurnOn() {
        std::cout << "Light turned on." << std::endl;
    }
    void TurnOff() {
        std::cout << "Light turned off." << std::endl;
    }
};

class TurnOnCommand : public Command {
    Light& light;
public:
    TurnOnCommand(Light& light) : light(light) {}
    void Execute() override {
        light.TurnOn();
    }
};

class TurnOffCommand : public Command {
    Light& light;
public:
    TurnOffCommand(Light& light) : light(light) {}
    void Execute() override {
        light.TurnOff();
    }
};

int main() 
{
    Light light;
    TurnOnCommand turnOn(light);
    TurnOffCommand turnOff(light);
    turnOn.Execute();
    turnOff.Execute();
    return 0;
}
