#ifndef AQUARIUM_H_
#define AQUARIUM_H_

#include "Fish.h"
#include <vector>

class Aquarium {
private:
    std::vector<Fish> fishList;
public:
    Aquarium();
    void AddFish(const Fish& fish);
    void GetInfo() const;
};

#endif /* AQUARIUM_H_ */