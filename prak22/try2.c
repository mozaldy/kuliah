#include <stdio.h>
#include <string.h>
#define max 255

int compare(char s1[max], char s2[max]);
int len(char s[]);

void main()
{
    char s1[max], s2[max];
    printf("Input string pertama: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Input string kedua: ");
    fgets(s2, sizeof(s2), stdin);

    printf(compare(s1, s2) == 1 ? "Sama" : "Tidak sama");
    printf("\n");
}

int compare(char s1[max], char s2[max])
{
    int count1 = 0, count2 = 0;
    for (int i = 0; i < len(s1); i++)
    {
        count1 += s1[i];
        count2 += s2[i];
    }
    return ((count1 == count2 && len(s1) == len(s2)) ? 1 : 0);
}

int len(char s[]){
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i - 1;
}