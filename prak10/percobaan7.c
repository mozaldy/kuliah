#include <stdio.h>

void main(){
    float a, b, c;
    int waktu = 0;

    printf("Masukkan berapa bilangan awal: ");
    scanf("%f", &a);
    printf("Berapa cicilan yang mampu dibayarkan tiap bulan: ");
    scanf("%f", &b);
    printf("Berapa rata-rata kenaikan setiap tahun (%%): ");
    scanf("%f", &c);

    while(a > 0){
        a -= b;
        waktu++;
        a += (waktu % 12 == 0) ? 25000000 * (c / 100) : 0;
    }
    printf("%d Bulan\n", waktu);
}