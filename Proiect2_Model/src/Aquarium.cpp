#include "../include/Aquarium.h"

Aquarium::Aquarium() = default;

void Aquarium::AddFish(const Fish &fish)
{
    fishList.push_back(fish);
}

void Aquarium::GetInfo() const
{
    std::cout << "We have " << fishList.size() << " fishes!\n";
}
