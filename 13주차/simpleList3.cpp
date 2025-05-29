#include <iostream>
#include <cstdlib>
#include <ctime>

class Sample {
    int list[100];

public:
    // 생성자: 배열을 난수로 초기화
    Sample() {
        std::srand(std::time(0));
        for (int x = 0; x < 100; x++) {
            list[x] = rand() % 1000;
        }
    }

    // 두 수의 곱에 해당하는 인덱스의 항목을 참조자로 반환 (쓰기/읽기 가능)
    int& operator()(int a, int b) {
        int index = a * b;
        if (index < 0 || index >= 100) {
            throw std::out_of_range("Index out of range (a * b must be in 0~99)");
        }
        return list[index];
    }

    // const 객체에서 사용 가능한 버전 (읽기 전용)
    const int& operator()(int a, int b) const {
        int index = a * b;
        if (index < 0 || index >= 100) {
            throw std::out_of_range("Index out of range (a * b must be in 0~99)");
        }
        return list[index];
    }

    // 배열 출력 (디버깅용)
    void printList() const {
        for (int x = 0; x < 100; x++) {
            std::cout << list[x] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Sample s;

    // 예: 2 * 5 = 10 → list[10]에 접근
    std::cout << "s(2, 5) = " << s(2, 5) << std::endl;

    // 값 수정
    s(2, 5) = 777;
    std::cout << "s(2, 5) = " << s(2, 5) << " (수정 후)" << std::endl;

    return 0;
}
