#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include "Tuman.h"
#include <time.h>
#include <conio.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	// 일반 몬스터 추가
	game.add(new Zombie("좀비", "◎", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어", "★", rand() % w, rand() % h));
	game.add(new KGhost("귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("강시↔", "↔", rand() % w, rand() % h, true));
	game.add(new Jiangshi("강시↕", "↕", rand() % w, rand() % h, false));

	// 마지막 두 명은 경기자 (Tuman)
	Tuman* leftPlayer = new Tuman("왼쪽", "좌", rand() % w, rand() % h, WASD);
	Tuman* rightPlayer = new Tuman("오른쪽", "우", rand() % w, rand() % h, ArrowKeys);
	game.add(leftPlayer);
	game.add(rightPlayer);

	// 경기자 포인터 (nMon은 내부적으로 증가됨)
	// pMon[nMon - 2] = 왼쪽 (좌), pMon[nMon - 1] = 오른쪽 (우)
	// 이 예제에서는 moveHuman을 활용하여 직접 입력 제어 가능

	game.play(300, 50); // 자동 move()를 호출
	printf("------게임 종료-------------------\n");
	getchar(); getchar();
}
