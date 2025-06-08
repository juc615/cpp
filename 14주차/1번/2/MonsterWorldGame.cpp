#include "MonsterWorld.h"
#include "Human.h"
#include "VariousMonsters.h"
#include <iostream>
#include <string>

int main() {
    std::string password;
    const std::string correctPassword = "1234";  // 2번 비밀번호

    std::cout << "비밀번호를 입력하세요: ";
    std::cin >> password;

    if (password != correctPassword) {
        std::cout << "비밀번호가 틀렸습니다. 프로그램을 종료합니다." << std::endl;
        return 1;
    }

    MonsterWorld world(10, 5);
    world.addMonster(new Human("Human1", 'H'));
    world.addMonster(new SimpleMonster("Simple1", 'S'));
    world.addMonster(new RandomMonster("Random1", 'R'));

    world.run();

    return 0;
}
