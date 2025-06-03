#include <iostream>
#include <stdexcept>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

    // 인덱스 연산자 중복 (읽기 전용)
    int operator[](int index) const {
        switch(index) {
            case 0: return hour;
            case 1: return min;
            case 2: return sec;
            default:
                throw out_of_range("Invalid index: must be 0 (hour), 1 (min), or 2 (sec)");
        }
    }

    // 출력 연산자
    friend ostream& operator<<(ostream& os, const TimeHMS& t) {
        os << t.hour << "h " << t.min << "m " << t.sec << "s";
        return os;
    }
};
