#include <stdio.h>

void main()
{
    float bilangan1, bilangan2;
    printf("Inputkan angka: ");
    scanf("%f %f", &bilangan1, &bilangan2);

    if (bilangan2 == 0)
        printf("Error: Cannot divide by 0!\n");
    else
        printf("Hasil pembagian dari %.0f dengan %.0f adalah %.3f\n", bilangan1, bilangan2, bilangan1/bilangan2);
}