#include <stdio.h>

void main()
{
    int uang, sisa, seratusk, limapuluhk, duapuluhk, sepuluhk, limak, duak, satuk;
    printf("Uang: ");
    scanf("%d", &uang);
    seratusk = uang / 100000;
    sisa = uang - (seratusk * 100000);
    printf("%d lembar 100k\n", seratusk);
    limapuluhk = sisa / 50000;
    sisa -= (limapuluhk * 50000);
    printf("%d lembar 50k\n", limapuluhk);
    duapuluhk = sisa / 20000;
    sisa -= (duapuluhk * 20000);
    printf("%d lembar 20k\n", duapuluhk);
    sepuluhk = sisa / 10000;
    sisa -= (sepuluhk * 10000);
    printf("%d lembar 10k\n", sepuluhk);
    limak = sisa / 5000;
    sisa -= (limak * 5000);
    printf("%d lembar 5k\n", limak);
    duak = sisa / 2000;
    sisa -= (duak * 2000);
    printf("%d lembar 2k\n", duak);
    satuk = sisa / 1000;
    sisa -= (satuk * 1000);
    printf("%d lembar 1k\n", satuk);
}