#include <stdio.h>

void main()
{
    int bilangan1, bilangan2; 
    printf("Inputkan angka: ");
    scanf("%d %d", &bilangan1, &bilangan2);
    
    if (bilangan1 % bilangan2 == 0)
        printf("Bilangan pertama adalah kelipatan persekutuan bilangan kedua\n");
    else
        printf("Bilangan pertama bukan kelipatan persekutuan bilangan kedua\n");


}