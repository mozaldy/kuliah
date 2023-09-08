#include <stdio.h>

void main()
{
    int n;
    printf("Angka ganjil dari 1 = ke n\nn: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i += 2)
    {
        printf("%d\n", i);
    }
}