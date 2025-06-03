#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

    // int형으로 변환하는 연산자 중복
    operator int() const {
        return hour * 3600 + min * 60 + sec;
    }

    friend ostream& operator<<(ostream& os, const TimeHMS& t) {
        os << t.hour << "h " << t.min << "m " << t.sec << "s";
        return os;
    }
};
