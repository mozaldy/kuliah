#include <stdio.h>

void main(){
    char pake_gets[]= "Saya ambil buff";
    char pake_scanf[30];
    char pake_fgets[30];

    printf("Pake gets: ");
    gets(pake_gets);
    printf("Pake scanf: ");
    scanf("%s", pake_scanf);
    getchar();
    printf("Pake fgets: ");
    fgets(pake_fgets, sizeof pake_fgets, stdin);

    printf("%s\n%s\n%s\n", pake_gets, pake_scanf, pake_fgets);
}