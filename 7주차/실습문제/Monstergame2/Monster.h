#pragma once
#include <string>
using namespace std;

class Monster {
private:
    string name;
    string shape;
    int x, y;
    int nEnergy; // (1) 에너지 변수 추가

public:
    Monster(string n = "이름없음", string s = "☆", int x = 0, int y = 0)
        : name(n), shape(s), x(x), y(y), nEnergy(100) {}  // (2) 에너지 100으로 초기화

    string getName() const { return name; }
    string getShape() const { return shape; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getEnergy() const { return nEnergy; }

    void setPos(int nx, int ny) { x = nx; y = ny; }

    // (3) 에너지 조작 함수도 필요
    void increaseEnergy(int val) { nEnergy += val; }
    void decreaseEnergy(int val) { 
        nEnergy -= val; 
        if (nEnergy < 0) nEnergy = 0;
    }
};
