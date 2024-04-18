#ifndef ABSTRACT_ANIMAL_H_
#define ABSTRACT_ANIMAL_H_

#include <iostream>

class AbstractAnimal{
private:
    static int idGenerator;
protected:
    std::string name;
    int age;
    const int id;
public:
    // functie virtuala pura care neaparat trebuie sa fie implementata de clasele derivate pt a fi instantiabile
    virtual void MakeSound() const = 0;
    // functie virtuala care poate sa fie implementata sau nu de clasele dereivate
    virtual void Describe() const;
    // functie implem de clasa abstracta care nu trebuie neaparat reimplementatata
    void WhatAmI() const;
    // operator de afisare pentru un animal abstract, stie pe ce functie de afisare sa se duca in fct de tipul animalului
    friend std::ostream& operator<<(std::ostream& os, const AbstractAnimal& animal);
    virtual ~AbstractAnimal();
protected:
    AbstractAnimal(const std::string& name_ = "", int age_ = -1);
    // functie virtuala pura de afisare redefinta in fiecare clasa derivata
    virtual void Afisare(std::ostream& os) const = 0;
    // destructor virtual pentru ca, posibil clasele derivate sa aloce dinamic resurse, sa se apeleze destr corespunzator
};

#endif /* ABSTRACT_ANIMAL_H_ */