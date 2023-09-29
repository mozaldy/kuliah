#include <stdio.h>

void main(){
    int input, nowNum = 0, nextNum = 1, fibo, fiboCount = 0;
    printf("Berapa angka fibo? ");
    scanf("%d", &input);
    while(fiboCount < input){
        fibo = nowNum + nextNum;
        printf("%d ", fibo);
        fiboCount++;
        nowNum = nextNum;
        nextNum = fibo;
    }
    printf("\n");
}