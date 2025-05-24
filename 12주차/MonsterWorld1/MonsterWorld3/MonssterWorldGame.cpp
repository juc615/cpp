#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include "Tuman.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("좀비", "◎", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어", "★", rand() % w, rand() % h));
	game.add(new KGhost("귀신", "♥", rand() % w, rand() % h));

	// Tuman 테스트용 추가
	Tuman* t1 = new Tuman("터먼1", "좌", rand() % w, rand() % h, WASD);
	Tuman* t2 = new Tuman("터먼2", "우", rand() % w, rand() % h, ArrowKeys);
	game.add(t1);
	game.add(t2);

	game.play(200, 50);
	printf("------게임 종료-------------------\n");
	getchar(); getchar();
}
