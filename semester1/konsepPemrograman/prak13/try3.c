#include <stdio.h>

float kuadrat(float n);

void main()
{
    int input;
    printf("Kuadratkan: ");
    scanf("%d", &input);
    printf("%g\n", kuadrat(input));
}

float kuadrat(float n)
{
    return n * n;
}