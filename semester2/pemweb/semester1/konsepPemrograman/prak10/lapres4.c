#include <stdio.h>

void main(){
    float a, b, c, d;
    int waktu = 0;

    printf("Masukkan berapa bilangan awal: ");
    scanf("%f", &a);
    printf("Berapa cicilan yang mampu dibayarkan tiap bulan: ");
    scanf("%f", &b);
    printf("Berapa rata-rata kenaikan setiap tahun (%%): ");
    scanf("%f", &c);
    printf("Bonus gaji: ");
    scanf("%f", &d);

    while(a > 0){
        a -= (waktu % 6 == 0) ? b + d : b;
        a += (waktu % 12 == 0) ? a * (c / 100) : 0;
        waktu++;
    }
    printf("%d Bulan\n", waktu);
}