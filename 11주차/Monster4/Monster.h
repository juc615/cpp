#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
protected:
	string name, icon;
	int x, y, nItem;

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
		}
	}
public:
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0) {}
	virtual ~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~\n"; }

	virtual void move(int** map, int maxx, int maxy) {
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

	void draw(Canvas& canvas) { canvas.draw(x, y, icon); }
	void print() { cout << "\t" << name << icon << ":" << nItem << endl; }
};
