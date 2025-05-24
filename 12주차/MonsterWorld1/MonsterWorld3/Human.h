#pragma once
#include "Monster.h"
#include <conio.h>

enum ControlScheme { ArrowKeys, WASD };

class Human : public Monster {
protected:
	ControlScheme control;
public:
	Human(string n, string i, int px, int py, ControlScheme c)
		: Monster(n, i, px, py), control(c) {}
	~Human() { cout << " [Human] "; }

	void move(int** map, int maxx, int maxy) override {
		if (_kbhit()) {
			char ch = _getch();
			if (control == ArrowKeys && ch == -32) ch = _getch();

			switch (control) {
				case ArrowKeys:
					if (ch == 75) x--;
					else if (ch == 77) x++;
					else if (ch == 72) y--;
					else if (ch == 80) y++;
					break;
				case WASD:
					if (ch == 'a') x--;
					else if (ch == 'd') x++;
					else if (ch == 'w') y--;
					else if (ch == 's') y++;
					break;
			}
			clip(maxx, maxy);
			eat(map);
		}
	}
};
