#include "include/AnimalLibrary.h"
#include <vector>

int main()
{
    std::vector<AbstractAnimal*> animale;

    animale.push_back(new Fish("peste1", 8, WaterType::WT_FRESH_WATER));
    animale.push_back(new Mammal("mammal1", 20, 4, 2));
    animale.push_back(new Bird("bird1", 5, "specie1"));


    for(AbstractAnimal* animal : animale)
    {
        std::cout << *animal;
        std::cout << "===\n";
    }

    for(AbstractAnimal* animal : animale)
    {
        delete animal;
    }
    return 0;
}


