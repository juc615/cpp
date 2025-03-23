#include <stdio.h>

int reverse(int n) {
    int reversedNum = 0;
    while (n > 0) {
        reversedNum = reversedNum * 10 + n % 10;
        n /= 10;
    }
    return reversedNum;
}

int main() {
    int x = 12345, z;
    z = reverse(x);
    printf("z=%d\n", z);  // z=54321
    return 0;
}
