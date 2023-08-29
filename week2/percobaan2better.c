#include <stdio.h>

int hitung();

void main()
{
    int uang, sisa;
    printf("Uang: ");
    scanf("%d", &uang);
    sisa = hitung(uang, 100000);
    sisa = hitung(sisa, 50000);
    sisa = hitung(sisa, 20000);
    sisa = hitung(sisa, 10000);
    sisa = hitung(sisa, 5000);
    sisa = hitung(sisa, 2000);
    sisa = hitung(sisa, 1000);
}

int hitung(int uang, int nominal)
{
    int lembar = uang / nominal;
    printf("%d lembar Rp. %d\n", lembar, nominal);
    uang = uang - (nominal * lembar);
    return uang;
}