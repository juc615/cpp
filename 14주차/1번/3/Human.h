#pragma once
#include "Monster.h"
#include <string>

class Human : public Monster {
public:
    Human(std::string name, char shape);
    virtual ~Human() = default;
    virtual void move() override;
};
