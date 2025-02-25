#include <stdio.h>

void main()
{
    int input, total = 0;
    printf("Input: ");
    scanf("%d", &input);
    while(input!=0){
        total += input % 10;
        input /= 10;
    }
    printf("Total = %d \n", total);
}