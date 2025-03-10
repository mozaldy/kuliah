#include <stdio.h>

void menu();

void main()
{
    char input = 'y';
    while (input == 'y')
    {
        menu();
        printf("Apakah mengulang?(y/t) ");
        scanf("%c", &input);
        getchar();
    }
}

void menu()
{
    printf("Menu Aldy'z Cell!\n");
}