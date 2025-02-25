#include <stdio.h>

void main()
{
    int input, n = 0, jarak = 1;
    printf("Input: ");
    scanf("%d", &input);
    while (jarak <= input)
    {
        printf("%d ", n);
        n += jarak;
        jarak++;
    }
    printf("\n");
}