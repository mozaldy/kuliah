#include <stdio.h>

void main()
{
    int n, hasil = 0;
    printf("Bilangan triangular dari n ke 1\nn: ");
    scanf("%d", &n);

    for (; n != 0; n--)
    {
        printf("%d", n);
        printf((n != 1) ? " + ":" = ");
        hasil += n;
    }
    printf("%d\n", hasil);


}