#include <stdio.h>

void main()
{
    int n;
    printf("Input: ");
    scanf("%d", &n);
    int fibo[n];
    
    for (int i = 0; i < n; i++)
    {
        if(i < 2)
            fibo[i] = i;
        else
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibo[i]);
    }
}