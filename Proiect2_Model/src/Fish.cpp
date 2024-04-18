#include "../include/Fish.h"

Fish::Fish(const std::string &name_, int age_, WaterType waterType_) : AbstractAnimal(name_, age_), waterType{ waterType_ }
{
    std::cout << "Created a fish\n";
}

void Fish::Afisare(std::ostream &os) const
{
    os << "Printing all data for fish with id " << id << std::endl;
}
void Fish::MakeSound() const
{
    std::string waterTypeStr = (waterType == WaterType::WT_FRESH_WATER) ? "Fresh Water" : "Salt Water";
    printf("Fish id[%d] %s with age %d living in waterType %s is making a sound\n", id, name.c_str(), age, waterTypeStr.c_str());
}

// = default ok, vedeti Bird.cpp destructor
Fish::~Fish()
{
    std::cout << "~Fish()\n";
}