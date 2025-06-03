#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {
        normalize();
    }

    // 정규화 함수: 생성자와 수동 호출용
    void normalize() {
        min += sec / 60;
        sec %= 60;
        hour += min / 60;
        min %= 60;
    }

    // == 연산자 중복
    bool operator==(const TimeHMS& other) const {
        return hour == other.hour && min == other.min && sec == other.sec;
    }

    // != 연산자 중복
    bool operator!=(const TimeHMS& other) const {
        return !(*this == other);  // == 연산자 재활용
    }

    // 출력 연산자 중복
    friend ostream& operator<<(ostream& os, const TimeHMS& t) {
        os << t.hour << "h " << t.min << "m " << t.sec << "s";
        return os;
    }
};
