#include <iostream>
#include <cstdlib>
#include <ctime>

class Sample {
    int list[100];

public:
    // 생성자
    Sample() {
        std::srand(std::time(0));
        for (int x = 0; x < 100; x++) {
            list[x] = rand() % 1000;
        }
    }

    // 함수 호출 연산자 중복 (쓰기/읽기 가능)
    int& operator()(int index) {
        if (index < 0 || index >= 100) {
            throw std::out_of_range("Index out of range");
        }
        return list[index];
    }

    // const 객체용 함수 호출 연산자 중복 (읽기 전용)
    const int& operator()(int index) const {
        if (index < 0 || index >= 100) {
            throw std::out_of_range("Index out of range");
        }
        return list[index];
    }

    // 배열 출력 함수
    void printList() const {
        for (int x = 0; x < 100; x++) {
            std::cout << list[x] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Sample s;

    // 값 출력 (읽기)
    std::cout << "s(10) = " << s(10) << std::endl;

    // 값 수정 (쓰기)
    s(10) = 55555;
    std::cout << "s(10) = " << s(10) << " (수정 후)" << std::endl;

    return 0;
}
