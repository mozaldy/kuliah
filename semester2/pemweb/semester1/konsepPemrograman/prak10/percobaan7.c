#include <stdio.h>

void main(){
    float a, b, c, sisa;
    int waktu = 0;

    printf("Masukkan berapa bilangan awal: ");
    scanf("%f", &a);
    printf("Berapa cicilan yang mampu dibayarkan tiap bulan: ");
    scanf("%f", &b);
    printf("Berapa rata-rata kenaikan setiap tahun (%%): ");
    scanf("%f", &c);
    sisa = a;
    while(sisa > 0){
        sisa -= b;
        waktu++;
        sisa += (waktu % 12 == 0) ? a * (c / 100) : 0;
    }
    printf("%d Bulan\n", waktu);
}   