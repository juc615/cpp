#include "MonsterWorld.h"
#include "Human.h"
#include "VariousMonsters.h"
#include "RankingBoard.h"
#include <iostream>
#include <string>

int main() {
    std::string password;
    const std::string correctPassword2 = "1234";  // 2번 비밀번호
    const std::string correctPassword3 = "4321";  // 3번 비밀번호

    std::cout << "비밀번호를 입력하세요: ";
    std::cin >> password;

    if (password != correctPassword2 && password != correctPassword3) {
        std::cout << "비밀번호가 틀렸습니다. 프로그램을 종료합니다." << std::endl;
        return 1;
    }

    MonsterWorld world(10, 5);
    world.addMonster(new Human("Human1", 'H'));
    world.addMonster(new SimpleMonster("Simple1", 'S'));
    world.addMonster(new RandomMonster("Random1", 'R'));
    world.run();

    RankingBoard board;
    board.addScore("Human1", 100);
    board.addScore("Simple1", 80);
    board.addScore("Random1", 90);

    board.print();

    // 3번 비밀번호 기능
    if (password == correctPassword3) {
        std::string saveFile;
        std::cout << "랭킹을 저장할 파일 이름을 입력하세요: ";
        std::cin >> saveFile;
        board.saveToFile(saveFile);
    }

    return 0;
}
