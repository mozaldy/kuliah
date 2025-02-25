#include <stdio.h>

void main()
{
    int bulan, tanggal;
    printf("Bulan: ");
    scanf("%d", &bulan);
    printf("Tanggal: ");
    scanf("%d", &tanggal);
    if (tanggal < 1 || tanggal > 31){
        bulan = 0;
    }
    if (bulan != 0)
        printf("Bintang anda adalah ");
    switch (bulan)
    {
    case 1:
        printf((tanggal <= 19 ? "Capricorn" : "Aquarius"));
        break;
    case 2:
        printf((tanggal <= 18 ? "Aquarius" : "Pisces"));
        break;
    case 3:
        printf((tanggal <= 20 ? "Pisces" : "Aries"));
        break;
    case 4:
        printf((tanggal <= 20 ? "Aries" : "Taurus"));
        break;
    case 5:
        printf((tanggal <= 20 ? "Taurus" : "Gemini"));
        break;
    case 6:
        printf((tanggal <= 20 ? "Gemini" : "Cancer"));
        break;
    case 7:
        printf((tanggal <= 22 ? "Cancer" : "Leo"));
        break;
    case 8:
        printf((tanggal <= 22 ? "Leo" : "Virgo"));
        break;
    case 9:
        printf((tanggal <= 22 ? "Virgo" : "Libra"));
        break;
    case 10:
        printf((tanggal <= 22 ? "Libra" : "Scorpio"));
        break;
    case 11:
        printf((tanggal <= 22 ? "Scorpio" : "Sagittarius"));
        break;
    case 12:
        printf((tanggal <= 21 ? "Sagittarius" : "Capricorn"));
        break;   
    default:
        break;
    }
    printf("\n");
}