#include <stdio.h>

void main()
{
    float n = 1, bilangan, total = 0, max = 0, min = 99999;
    char input;
    while(input != 't'){
        printf("Masukkan bilangan ke-%.0f : ", n);
        scanf("%f", &bilangan);
        fflush(stdin);
        
        if (bilangan > max)
            max = bilangan;

        if (bilangan < min)
            min = bilangan;
        n++;
        total += bilangan;
        printf("Mau masukkan data lagi [y/t] ? ");
        scanf("%c", &input);
    }
    printf("Max: %.0f\n", max);
    printf("Min: %.0f\n", min);
    printf("Rata-rata = %.1f\n", (total / n));
    printf("Total bilangan = %.1f\n", total);
}