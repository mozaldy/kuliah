#include <stdio.h>

void main(){
    float a, b, c, hasil;
    printf("Input a:\n");
    scanf(" %f", &a);
    printf("Input b:\n");
    scanf(" %f", &b);
    printf("Input c:\n");
    scanf(" %f", &c);
    hasil = (b * b) - (4 * a * c);
    printf("%.2f\n", hasil);
}