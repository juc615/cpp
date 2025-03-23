#include <stdio.h>

int reverse(int);  

int main() 
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num); 

    int reversedNum = reverse(num); 
    printf("Reversed: %d\n", reversedNum);  

    return 0;  // 정상 종료
}


int reverse(int n)
{
    int result = 0;
    while (n != 0)  
    {
        result = result * 10 + (n % 10); 
        n /= 10;  
    }
    return result;
}
