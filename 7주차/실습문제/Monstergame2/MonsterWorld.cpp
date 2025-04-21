#include "MonsterWorld.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));  // 랜덤 시드 설정

	int w = 16, h = 8;  // 맵 크기 설정

	MonsterWorld game(w, h);  // 게임 생성

	// 랜덤 위치에 몬스터 추가
	Monster m("몬스터", "※", rand() % w, rand() % h);
	game.add(m);
	game.add(Monster("도깨비", "◎", rand() % w, rand() % h));
	game.add(Monster("별그대", "★", rand() % w, rand() % h));
	game.add(Monster("고스트", "♥", rand() % w, rand() % h));

	// 게임 시작
	game.play(500, 10);

	printf("------게임 종료-------------------\n");
}
