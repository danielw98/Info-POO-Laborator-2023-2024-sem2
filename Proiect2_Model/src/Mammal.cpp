#include "../include/Mammal.h"


Mammal::Mammal(const std::string &name_, int age_, int numberOfLegs_, int numberOfChildren_) 
    : AbstractAnimal(name_, age_), numberOfLegs {numberOfLegs_}, numberOfChildren { numberOfChildren_ }
{
    if(numberOfChildren == 0)
        children = nullptr;
    else
        children = new Mammal[numberOfChildren];
    std::cout << "Created a mammal\n";
}



void Mammal::MakeSound() const
{
    printf("Mammal id[%d] %s with age %d with %d children is making a sound\n", id, name.c_str(), age, numberOfChildren);
}

void Mammal::Afisare(std::ostream& os) const
{
    os << "Printing all data for mammal with id " << id << std::endl;
}


Mammal::Mammal(const Mammal& other) : AbstractAnimal(other)
{
    numberOfChildren = other.numberOfChildren;
    if(numberOfChildren != 0)
    {
        children = new Mammal[numberOfChildren];
        for(int i = 0; i < numberOfChildren; i++)
            children[i] = other.children[i];
    }
}
// operator= atribuire prin copiere
Mammal& Mammal::operator=(const Mammal& other)
{
    if(this != &other)
    {
        numberOfChildren = other.numberOfChildren;

    }
    return *this;
}

// constructor de mutare
Mammal::Mammal(Mammal&& other) : numberOfChildren{other.numberOfChildren}, children{other.children}
{
    other.numberOfChildren = -1;
    other.children = nullptr;
}

// operator= atribuire prin mutare
Mammal& Mammal::operator=(Mammal&& other)
{
    if(this != &other)
    {
        numberOfChildren = other.numberOfChildren;
        children = other.children;
        other.numberOfChildren = -1;
        other.children = nullptr;
    }
    return *this;
}


Mammal::~Mammal()
{
    std::cout << "~Mammal()\n";
    delete[] children;
}