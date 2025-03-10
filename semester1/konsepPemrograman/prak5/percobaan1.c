#include <stdio.h>

void main()
{
    int angka; 
    printf("Inputkan angka: ");
    scanf("%d", &angka);
    printf("%d adalah angka ", angka);
    printf((angka >= 0) ? "positif\n" : "negatif\n");
}