#pragma once
#include "Human.h"

class Tuman : public Human {
public:
	Tuman(string n, string i, int px, int py, ControlScheme c)
		: Human(n, i, px, py, c) {}

	// 입력된 문자로만 움직임 제어 (kbhit 사용 안 함)
	void moveHuman(char ch) {
		if (control == ArrowKeys) {
			switch (ch) {
				case 75: x--; break; // ←
				case 77: x++; break; // →
				case 72: y--; break; // ↑
				case 80: y++; break; // ↓
			}
		}
		else if (control == WASD) {
			switch (ch) {
				case 'a': x--; break;
				case 'd': x++; break;
				case 'w': y--; break;
				case 's': y++; break;
			}
		}
		clip(DIM, DIM); // 화면 벗어나지 않도록
	}
};
