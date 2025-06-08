#pragma once
#include "Canvas.h"
#include "Monster.h"
#include <vector>
#include <string>

class MonsterWorld {
private:
    Canvas canvas_;
    std::vector<Monster*> monsters_;
public:
    MonsterWorld(int width, int height);
    ~MonsterWorld();
    void addMonster(Monster* monster);
    void run();
};
