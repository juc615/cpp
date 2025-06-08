#pragma once
#include "Monster.h"
#include <cstdlib>

class SimpleMonster : public Monster {
public:
    SimpleMonster(std::string name, char shape);
    virtual void move() override;
};

class RandomMonster : public Monster {
public:
    RandomMonster(std::string name, char shape);
    virtual void move() override;
};
