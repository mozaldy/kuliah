#include <stdio.h>

void main()
{
    float n;
    scanf("%f", &n);
    for (float i = 2; i < n; i++)
    {
        float a = n / i;
        if (a % 2 == 0)
        {
            printf("bukan angka prima\n");
            return;
        }
    }
    printf("Angka prima\n");
}