#include <stdio.h>

void triangular(int n);

void main()
{
    int input;
    printf("Bilangan triangular: ");
    scanf("%d", &input);
    triangular(input);
}

void triangular(int n)
{
    int hasil = 0;
    for (; n != 0; n--)
    {
        printf("%d", n);
        printf((n != 1) ? " + " : " = ");
        hasil += n;
    }
    printf("%d\n", hasil);
}