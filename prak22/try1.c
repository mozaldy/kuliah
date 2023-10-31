#include <stdio.h>
#include <string.h>

int rev(char s[]);

char reversed[100];
char copied[100];

void main(int argc, char const *argv[])
{
    char input[100];
    printf("\033[1;35mDEMO LIBRARY STRING.H\n\033[1;0m");

    printf("Input string: ");
    fgets(input, sizeof(input), stdin);
    printf("Length: %lu\n", strlen(input));

    rev(input);
    printf("Reverse: %s \n", reversed);
    strcpy(copied, input);
    printf("Copy: %s \n", copied);
}

int rev(char s[])
{
    for (int i = strlen(s), rev_i = 0; i != 0; i--, rev_i++)
        reversed[rev_i] = s[i - 1];
}