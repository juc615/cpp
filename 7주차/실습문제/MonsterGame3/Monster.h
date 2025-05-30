#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
	string name, icon;	// 몬스터 이름과 화면 출력용 아이콘
	int x, y, nItem, energy; // 위치, 아이템 수, 에너지

	void clip(int maxx, int maxy) {
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}

	void eat(int map[DIM][DIM]) {
		if (map[y][x] == 1) {
			map[y][x] = 0;
			nItem++;
			energy += 8;  // 아이템 먹으면 에너지 증가
		} else {
			energy -= 1;  // 못 먹으면 에너지 감소
			if (energy < 0) energy = 0;
		}
	}

public:
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0), energy(10) {}

	~Monster() {
		cout << "\t" << name << icon << " 물러갑니다~~~\n";
	}

	void draw(Canvas &canvas) {
		canvas.draw(x, y, icon);
	}

	void move(int map[DIM][DIM], int maxx, int maxy) {
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
		cout << "\t" << name << icon << ":" << nItem 
		     << " (에너지: " << energy << ")" << endl;
	}
};
