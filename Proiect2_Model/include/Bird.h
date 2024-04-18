#ifndef BIRD_H_
#define BIRD_H_

#include "AbstractAnimal.h"
#include "IFlyingAnimal.h"

class Bird : public AbstractAnimal, public IFlyingAnimal {
private:
    static int speciesCount;
    std::string birdSpeices;
public:
    Bird(const std::string& name_ = "", int age_ = -1, const std::string& birdSpecies_ = "");
    static int GetSpeciesCount();
    static void AddNewSpecies();
    static void RemoveExistingSpecies();
    void Afisare(std::ostream& os) const override;
    void MakeSound() const override;
    // fac override pt o functie virtuala din clasa de baza care nu trebuie neaparat suprascrisa
    // deoarece are implementare, nu este virtuala pura
    void Describe() const override;
    ~Bird() override;

    // implementare interfata
    void Fly() const override;
};

#endif /* BIRD_H_ */