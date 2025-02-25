#include <stdio.h>

void main()
{
    int bilangan;
    printf("Inputkan angka: ");
    scanf("%d", &bilangan);

    bilangan = (bilangan < 0) ? bilangan * -1 : bilangan;
    
    printf("Output absolut: %d\n", bilangan);
}