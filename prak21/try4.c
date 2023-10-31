#include <stdio.h>

void copy(char input[], char output[]);

void main(int argc, char const *argv[])
{
    char input[100], output[100];
        printf("\033[1;35mDEMO IMITASI STRCPY()\n\033[1;0m");

    printf("Input string: ");
    fgets(input, sizeof(input), stdin);
    copy(input, output);
    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

}

void copy(char input[], char output[]){
    for (int i = 0; input[i] != '\0'; i++){
        output[i] = input[i];
    }
}