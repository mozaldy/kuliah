#include <stdio.h>

void rubah(int *, int *);

void main(){
    int n, r;
    printf("Angka pertama: ");
    scanf("%d", &n);
    printf("Angka kedua: ");
    scanf(" %d", &r);
    rubah(&n, &r);
    printf("---ANGKA DIRUBAH + 2---\n");
    printf("Angka pertama: %d\n", n);
    printf("Angka kedua: %d\n", r);
}

void rubah(int *a, int *b){
    *a += 2;
    *b += 2;
}