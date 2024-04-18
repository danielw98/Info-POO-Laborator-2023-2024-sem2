#include "../include/AbstractAnimal.h"

int AbstractAnimal::idGenerator = 1;

void AbstractAnimal::Describe() const
{
    printf("Describing an abstract animal with name %s and age %d\n", name.c_str(), age);
}

void AbstractAnimal::WhatAmI() const
{
    std::cout << "I am an abstract animal! :-)\n";
}

AbstractAnimal::AbstractAnimal(const std::string& name_, int age_) : name{ name_ }, age{ age_ }, id {idGenerator++}
{
    std::cout << "Created an absract animal\n";
}

std::ostream &operator<<(std::ostream &os, const AbstractAnimal &animal)
{
    os << "Name: " << animal.name << "\t" << "Age: " << animal.age << std::endl;
    animal.Afisare(os);
    return os;
}


AbstractAnimal::~AbstractAnimal() = default;