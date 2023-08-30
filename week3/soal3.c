#include <stdio.h>

int main()
{
    int input, jawab;
    printf("Polynomial = 3x^2 - 5x + 6 \n");
    printf("Input nilai x: ");
    scanf("%d", &input);
    jawab = 3 * (input * input) - 5 * input + 6;
    printf("Jawab = %d\n", jawab);
}