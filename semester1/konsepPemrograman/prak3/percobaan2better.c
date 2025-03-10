#include <stdio.h>

int hitung();

void main()
{
    int uang;
    printf("Uang: ");
    scanf("%d", &uang);
    uang = hitung(uang, 100000);
    uang = hitung(uang, 50000);
    uang = hitung(uang, 20000);
    uang = hitung(uang, 10000);
    uang = hitung(uang, 5000);
    uang = hitung(uang, 2000);
    uang = hitung(uang, 1000);
}

int hitung(int uang, int nominal)
{
    int lembar = uang / nominal;
    printf("%d lembar Rp. %d\n", lembar, nominal);
    uang = uang - (nominal * lembar);
    return uang;
}