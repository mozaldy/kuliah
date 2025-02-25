#include <stdio.h>

void main()
{
    int x, y, b, c;
    x = 5;
    b = 6;
    c = 7;
    y = (b * (x * x)) + (0.5 * x) - c;
    printf("%d\n", y);
}