#include "../include/Bird.h"

int Bird::speciesCount = 3;

Bird::Bird(const std::string &name_, int age_, const std::string& birdSpecies_) : AbstractAnimal(name_, age_), birdSpeices{birdSpecies_}
{
    AddNewSpecies();
    std::cout << "Created a bird\n";
}

int Bird::GetSpeciesCount()
{
    return speciesCount;
}

void Bird::AddNewSpecies()
{
    speciesCount++;
}

void Bird::RemoveExistingSpecies()
{
    // aici aruncam o exceptie daca sunt zero specii si totusi incercam sa scadem nr
    // voi aruncati exceptie din clasa personalizata cum am ilustrat in lab08
    // if(speciesCount == 0)
    //     throw std::logic_error("Species count cannot be less than zero\n");
    speciesCount--;
}

void Bird::Afisare(std::ostream &os) const
{
    os << "Printing all data for bird with id " << id << std::endl;
}

void Bird::MakeSound() const
{
    printf("Bird id[%d] %s species %s with age %d with %d number of species is making a sound\n", 
        id, name.c_str(), birdSpeices.c_str(), age, speciesCount);
}
void Bird::Describe() const
{
    // pot adauga si alte info specifice, nu doar sa schimb mesajul de print, override-ul trebuie sa fie cu sens
    printf("Describing a bird with name %s and age %d\n", name.c_str(), age);
}

// = default pt ca nu are date alocate dinamic, implem default e suficienta
Bird::~Bird()
{
    std::cout << "~Bird()\n";
}

void Bird::Fly() const
{
    std::cout << "The bird is flying!\n";
}