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

    // 출력 편의
    friend ostream& operator<<(ostream& os, const TimeHMS& t) {
        os << t.hour << "h " << t.min << "m " << t.sec << "s";
        return os;
    }

    // int와 TimeHMS 곱셈 friend 선언
    friend TimeHMS operator*(int lhs, const TimeHMS& rhs);
};

// int * TimeHMS 곱셈 연산자 중복 (비멤버 함수)
TimeHMS operator*(int lhs, const TimeHMS& rhs) {
    int totalSec = rhs.toSeconds() * lhs;  // 전체 초를 곱함
    TimeHMS result;
    result.fromSeconds(totalSec);          // 다시 시/분/초로 변환
    return result;
}
