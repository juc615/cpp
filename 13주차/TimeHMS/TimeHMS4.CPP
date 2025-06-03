#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

    // 초 단위로 환산
    int toSeconds() const {
        return hour * 3600 + min * 60 + sec;
    }

    // 초를 시:분:초로 변환
    void fromSeconds(int totalSec) {
        if (totalSec < 0) totalSec = 0;  // 음수 방지
        hour = totalSec / 3600;
        totalSec %= 3600;
        min = totalSec / 60;
        sec = totalSec % 60;
    }

public:
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

    // 전위 증가 연산자 ++t
    TimeHMS& operator++() {
        int totalSec = toSeconds() + 1;
        fromSeconds(totalSec);
        return *this;
    }

    // 전위 감소 연산자 --t
    TimeHMS& operator--() {
        int totalSec = toSeconds() - 1;
        fromSeconds(totalSec);
        return *this;
    }

    // 출력 연산자
    friend ostream&
