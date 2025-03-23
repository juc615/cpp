#include "reverse.h"  // 헤더 파일 포함

int reverse(int n) {
    int reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return reversed;
}
