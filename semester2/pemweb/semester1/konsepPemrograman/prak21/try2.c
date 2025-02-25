#include <stdio.h>

int len(char s[]);

void main()
{
    char input[100];
    printf("\033[1;35mDEMO IMITASI STRLEN()\n\033[1;0m");
    printf("Input string: ");
    fgets(input, sizeof(input), stdin);
    int panjang_string = len(input);
    printf("Panjang dari string adalah: %d\n", panjang_string);
}

int len(char s[]){
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i - 1;
}