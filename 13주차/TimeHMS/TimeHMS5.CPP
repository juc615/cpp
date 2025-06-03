#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

    int toSeconds() const {
        return hour * 3600 + min * 60 + sec;
    }

    void fromSeconds(int totalSec) {
        if (totalSec < 0) totalSec = 0;
        hour = totalSec / 3600;
        totalSec %= 3600;
        min = totalSec / 60;
        sec = totalSec % 60;
    }

public:
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

    // 후위 증가 연산자 t++
    TimeHMS operator++(int) {
        TimeHMS temp = *this;       // 현재 상태 저장
        fromSeconds(toSeconds() + 1);  // 1초 증가
        return temp;                // 변경 전 상태 반환
    }

    // 후위 감소 연산자 t--
    TimeHMS operator--(int) {
        TimeHMS temp = *this;
        fromSeconds(toSeconds() - 1);  // 1초 감소 (음수는 0으로 유지)
        return temp;
    }

    friend ostream& operator<<(ostream& os, const TimeHMS& t) {
        os << t.hour << "h " << t.min << "m " << t.sec << "s";
        return os;
    }
};
