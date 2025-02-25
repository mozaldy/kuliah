#include <stdio.h>
#include <string.h>
#define MAX 255

void main(){
    char s1[MAX], s2[MAX];
    printf("Input string pertama: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Input string kedua: ");
    fgets(s2, sizeof(s2), stdin);

    printf("%d\n", strcmp(s1, s2));
    printf("%d\n", strcasecmp(s1, s2));
}