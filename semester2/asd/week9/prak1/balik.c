#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void reverse(int, char *);
char reversal[255];
int i = 0;
int main(){
    char kalimat[255];
    printf("Input kalimat: ");
    scanf("%s", kalimat);
    reverse(strlen(kalimat), kalimat);
    printf("balik = %s\n", reversal);
}
void reverse(int len, char *kalimat){
    reversal[i] = kalimat[len -1];
    len--;
    i++;
    if (len)
        reverse(len, kalimat);
}