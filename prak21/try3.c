#include <stdio.h>

int len(char s[]);
int rev(char s[]);

char reversed[100];

void main(int argc, char const *argv[])
{
    char input[100];
    printf("\033[1;35mDEMO IMITASI STRREV()\n\033[1;0m");

    printf("Input string: ");
    fgets(input, sizeof(input), stdin);

    int panjang_string = len(input);
    rev(input);
    printf("Reverse string adalah: \n");
    printf("%s", input);
    printf("%s", reversed);
    printf("\n");
}

int len(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

int rev(char s[])
{
    for (int i = len(s), rev_i = 0; i != 0; i--, rev_i++)
        reversed[rev_i] = s[i - 1];
}