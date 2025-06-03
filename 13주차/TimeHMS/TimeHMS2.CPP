#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

    // 초 단위로 전체 시간 변환
    int toSeconds() const {
        return hour * 3600 + min * 60 + sec;
    }

    // 초를 시:분:초로 변환하는 정규화 함수
    void fromSeconds(int totalSec) {
        if (totalSec < 0) totalSec = 0;  // 음수 시간 허용하지 않음
        hour = totalSec / 3600;
        totalSec %= 3600;
        min = totalSec / 60;
        sec = totalSec % 60;
    }

public:
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

    // - 연산자 중복
    TimeHMS operator-(const TimeHMS& other) const {
        int diffSec = this->toSeconds() - other.toSeconds();
        TimeHMS result;
        result.fromSeconds(diffSec);
        return result;
    }

    // 출력 연산자 중복
    friend ostream& operator<<(ostream& os, const TimeHMS& t) {
        os << t.hour << "h " << t.min << "m " << t.sec << "s";
        return os;
    }
};
