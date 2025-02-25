#include <stdio.h>

void main()
{
    int n = 1, bilangan, total = 0;
    char input;
    while(input != 't'){
        printf("Masukkan bilangan ke-%d : ", n);
        scanf("%d", &bilangan);
        fflush(stdin);
        n++;
        total += bilangan;
        printf("Mau masukkan data lagi [y/t] ? ");
        scanf("%c", &input);
    }
    printf("Total bilangan = %d\n", total);
}