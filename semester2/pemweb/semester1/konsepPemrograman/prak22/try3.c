#include <stdio.h>
#include <string.h>
#define max 255

int compare2(char s1[max], char s2[max]);
int len(char s[]);

void main()
{
    char s1[max], s2[max];
    printf("Input string pertama: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Input string kedua: ");
    fgets(s2, sizeof(s2), stdin);

    printf(compare2(s1, s2) == 1 ? "Sama" : "Tidak sama");
    printf("\n");
}

int compare2(char s1[max], char s2[max])
{
    int count1 = 0, count2 = 0;
    for (int i = 0; i < strlen(s1); i++)
    {
        count1 += s1[i];
        count2 += s2[i];
        if(s1[i] >= 97)
            count1 -= 32;
        if(s2[i] >= 97)
            count2 -= 32;
    }
    return ((count1 == count2 && strlen(s1) == strlen(s2)) ? 1 : 0);
}
