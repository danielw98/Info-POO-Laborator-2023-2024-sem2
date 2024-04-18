#ifndef MAMMAL_H_
#define MAMMAL_H_

#include "./AbstractAnimal.h"

class Mammal : public AbstractAnimal {
private:
    int numberOfLegs;
    Mammal *children; // std::vector<Mammal> children
    int numberOfChildren;
public:
    Mammal(const std::string& name_ = "", int age_ = -1, int numberOfLegs_ = -1, int numberOfChildren_ = 0);
    // constructor copiere
    Mammal(const Mammal& other);
    // operator= atribuire prin copiere
    Mammal& operator=(const Mammal& other);
    // constructor de mutare
    Mammal(Mammal&& other);
    // operator= atribuire prin mutare
    Mammal& operator=(Mammal&& other);
    void MakeSound() const override;
    void Afisare(std::ostream& os) const override;
    // ctor
    // regula celor 5 (rule of 5)
    ~Mammal() override;
};

#endif /* MAMMAL_H_ */