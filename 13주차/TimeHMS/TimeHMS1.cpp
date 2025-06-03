#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

    // 내부 정규화 함수: 60초 → 1분, 60분 → 1시간
    void normalize() {
        if (sec >= 60) {
            min += sec / 60;
            sec %= 60;
        }
        if (min >= 60) {
            hour += min / 60;
            min %= 60;
        }
    }

public:
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {
        normalize();  // 생성 시 자동 정규화
    }

    // + 연산자 중복
    TimeHMS operator+(const TimeHMS& other) const {
        TimeHMS temp;
        temp.hour = hour + other.hour;
        temp.min = min + other.min;
        temp.sec = sec + other.sec;
        temp.normalize();  // 더한 후 정규화
        return temp;
    }

    // 출력용 friend 함수
    friend ostream& operator<<(ostream& os, const TimeHMS& t) {
        os << t.hour << "h " << t.min << "m " << t.sec << "s";
        return os;
    }
};
