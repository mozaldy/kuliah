#include <stdio.h>

void main()
{
    int x, y, z, a;
    x = 5;
    z = 6;
    a = 7;
    y = (0,3 * x * z) / (2 * a);
    printf("%d\n", y);
}