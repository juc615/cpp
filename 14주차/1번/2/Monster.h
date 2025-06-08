#pragma once
#include "Canvas.h"
#include "Point.h"
#include <string>

class Monster {
protected:
    std::string name_;
    Point location_;
    char shape_;
    Canvas* canvas_;

public:
    Monster(std::string name, char shape);
    virtual ~Monster();
    void setCanvas(Canvas* canvas);
    virtual void move() = 0;
    virtual void draw();
    std::string getName() const;
    Point getLocation() const;
};
