#include <iostream>
#include <locale>
using namespace std;

class MyTime {
    int hour, minute, second, millisecond;

public:
    // 기본 생성자
    MyTime() : hour(0), minute(0), second(0), millisecond(0) {
        cout << "[기본 생성자 호출]" << endl;
    }

    // int 타입 생성자
    MyTime(int h, int m, int s, int ms)
        : hour(h), minute(m), second(s), millisecond(ms) {
        cout << "[int 매개변수 생성자 호출]" << endl;
    }

    // double 타입 생성자 → int 생성자로 위임
    MyTime(double duration)
        : MyTime(
            static_cast<int>(duration) / 3600,
            (static_cast<int>(duration) % 3600) / 60,
            static_cast<int>(duration) % 60,
            static_cast<int>((duration - static_cast<int>(duration)) * 1000)
        )
    {
        cout << "[double → int 생성자 위임 호출됨]" << endl;
    }

    void print() {
        cout << hour << "시간 " << minute << "분 " << second << "초 " << millisecond << "밀리초" << endl;
    }
};

int main() {
    // 시스템에 따라 로케일 설정을 "ko_KR.utf8"로 변경할 수도 있음
    setlocale(LC_ALL, "ko_KR.utf8"); // 이 부분은 OS에 따라 달라질 수 있음

    MyTime t(3661.789); // 1시간 1분 1초 789밀리초
    t.print();  // 1시간 1분 1초 789밀리초 출력

    return 0;
}
