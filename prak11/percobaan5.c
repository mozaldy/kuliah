#include <stdio.h>

void main()
{
    int input;
    printf("Input angka: ");
    scanf("%d", &input);
    for (int i = 1; i <= input; i++)
    {
        for (int j = 1; j <= input; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    
}