#include <stdio.h>

int sempurna(int);

void main()
{
    int input;
    printf("Bilangan: ");
    scanf("%d", &input);
    printf(sempurna(input) ? "Bilangan sempurna\n" : "Bukan bilangan sempurna\n");
}

int sempurna(int n)
{
    int bayangan = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            bayangan += i;
    }
    if (n == bayangan)
        return 1;
    return 0;
}