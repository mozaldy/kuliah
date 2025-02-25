#include <stdio.h>
int ganjil(int);

void main(){
    int input;
    printf("Input: ");
    scanf("%d", &input);
    printf(ganjil(input) == 1 ? "Ganjil\n" : "Genap\n");
}

int ganjil(int n){
    return (n % 2 == 0 ? 0 : 1);
}