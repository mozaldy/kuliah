#include <stdio.h>

void main(){
    int a, b, c, hasil;
    printf("Input a:\n");
    scanf(" %d", &a);
    printf("Input b:\n");
    scanf(" %d", &b);
    printf("Input c:\n");
    scanf(" %d", &c);
    hasil = (b * b) - (4 * a * c);
    printf("%d\n", hasil);
}