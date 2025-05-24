#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("좀비", "◎", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어", "★", rand() % w, rand() % h));
	game.add(new KGhost("귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("강시↔", "↔", rand() % w, rand() % h, true));
	game.add(new Jiangshi("강시↕", "↕", rand() % w, rand() % h, false));

	game.add(new Human("Player1", "좌", rand() % w, rand() % h, WASD));       // WASD
	game.add(new Human("Player2", "우", rand() % w, rand() % h, ArrowKeys));  // 방향키

	game.play(500, 30);
	printf("------게임 종료-------------------\n");
	getchar(); getchar();
}
