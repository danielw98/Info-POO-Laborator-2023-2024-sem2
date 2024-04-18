#ifndef FISH_H_
#define FISH_H_

#include "AbstractAnimal.h"
#include "enums/WaterType.h"

class Fish : public AbstractAnimal {
private:
    WaterType waterType;
public:
    Fish(const std::string& name_ = "", int age_ = -1, WaterType waterType_ = WaterType::WT_NONE);
    void Afisare(std::ostream& os) const override;
    void MakeSound() const override;
    ~Fish() override;
};

#endif /* FISH_H_ */