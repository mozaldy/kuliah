#include <stdio.h>

void main()
{
    int n, hasil = 0;
    printf("Angka ganjil dari 1 = ke n\nn: ");
    scanf("%d", &n);

    for (; n != 0; n--)
    {
        printf("%d", n);
        printf((n != 1) ? " + ":" = ");
        hasil += n;
    }
    printf("%d\n", hasil);


}