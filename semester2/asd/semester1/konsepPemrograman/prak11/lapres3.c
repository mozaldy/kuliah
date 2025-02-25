#include <stdio.h>

void main()
{
    int input, i = 2, n = 0;
    printf("Input n: ");
    scanf("%d", &input);
    while(n < input){
        int pembagi = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                pembagi++;
        }
        if (pembagi == 0){
            printf("%d ", i);
            n++;
        }
        i++;
    }
    printf("\n");
}