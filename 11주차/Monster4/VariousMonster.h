#pragma once
#include "Monster.h"

class Zombie : public Monster {
public:
	Zombie(string n = "허접한좀비", string i = "◎", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "뱀파이어짱", string i = "★", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) override {
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "어쩌다귀신", string i = "♥", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) override {
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {
protected:
	bool bHori;
public:
	Jiangshi(string n = "강시", string i = "↔", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	virtual void move(int** map, int maxx, int maxy) override {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori)
			x += ((dir == 0) ? -jump : jump);
		else
			y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Smombi : public Monster {
public:
	Smombi(string n = "스몸비", string i = "◇", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Smombi() { cout << " Smombi"; }

	void move(int** map, int maxx, int maxy) override {
		switch (rand() % 4) {
		case 0: x--; y--; break;  // 좌상
		case 1: x++; y--; break;  // 우상
		case 2: x++; y++; break;  // 우하
		case 3: x--; y++; break;  // 좌하
		}
		clip(maxx, maxy);
		eat(map);
	}
};

class Siangshi : public Jiangshi {
	int moveCount;
	int changeInterval;
public:
	Siangshi(string n = "수퍼강시", string i = "☆", int x = 0, int y = 0, int interval = 10)
		: Jiangshi(n, i, x, y, true), moveCount(0), changeInterval(interval) {}

	void move(int** map, int maxx, int maxy) override {
		if (++moveCount >= changeInterval) {
			bHori = !bHori;  // 방향 전환
			moveCount = 0;
		}
		Jiangshi::move(map, maxx, maxy);  // 기존 강시 방식 호출
	}
};

class Blinker : public Monster {
	bool doTeleport;
public:
	Blinker(string n = "블링커귀신", string i = "¤", int x = 0, int y = 0)
		: Monster(n, i, x, y), doTeleport(true) {}
	~Blinker() { cout << " Blinker"; }

	void move(int** map, int maxx, int maxy) override {
		if (doTeleport) {
			// 순간이동
			x = rand() % maxx;
			y = rand() % maxy;
		} else {
			// 주변 8방향 이동
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
		}
		doTeleport = !doTeleport;
		clip(maxx, maxy);
		eat(map);
	}
};
