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
			bHori = !bHori;
			moveCount = 0;
		}
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
