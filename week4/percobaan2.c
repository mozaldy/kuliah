#include <stdio.h>

void main()
{
    int angka; 
    printf("Inputkan angka: ");
    scanf("%d", &angka);
    printf("Bilangan yang diinputkan adalah %d.\nBilangan tersebut adalah bilangan ", angka);
    printf((angka %2 == 0) ? "Genap\n" : "Ganjil\n");
}