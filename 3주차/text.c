#include <stdio.h>

// 함수 선언
int reverse(int);

int main() {
    int num, result;
    
    printf("정수를 입력하세요: ");
    scanf("%d", &num);
    
    result = reverse(num);
    printf("역순 숫자: %d\n", result);
    
    return 0;
}

// 정수를 뒤집는 함수 정의
int reverse(int n) {
    int reversedNum = 0;
    
    while (n > 0) {
        reversedNum = reversedNum * 10 + (n % 10); // 마지막 자리 숫자를 추가
        n /= 10; // 한 자리 줄이기
    }
    
    return reversedNum;
}
