#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
    string name, icon;    // 몬스터 이름과 아이콘
    int x, y, nItem;      // 현재 위치와 먹은 아이템 수
    int energy;           // 에너지 속성 추가

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    void eat(int** map) {
        if (map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
            energy += 10;  // 아이템을 먹으면 에너지 +10
        }
    }

public:
    Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nItem(0), energy(100) {}  // 초기 에너지 100 설정

    ~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~\n"; }

    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }

    void move(int** map, int maxx, int maxy) {
        switch (rand() % 8) {
            case 0: y--; break;
            case 1: x++; y--; break;
            case 2: x++; break;
            case 3: x++; y++; break;
            case 4: y++; break;
            case 5: x--; y++; break;
            case 6: x--; break;
            case 7: x--; y--; break;
        }
        clip(maxx, maxy);
        eat(map);
    }

    void print() {
        cout << "\t" << name << icon
             << " : 아이템=" << nItem
             << ", 에너지=" << energy << endl;
    }
};
