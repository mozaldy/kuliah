#include <stdio.h>

int max_num(int *, int *);

void main(){
    int a, b;
    printf("Bilangan 1: ");
    scanf("%d", &a);
    printf("Bilangan 2: ");
    scanf(" %d", &b);
    printf("Angka terbesar dari %d dan %d adalah %d\n", a, b, max_num(&a, &b));
}

int max_num(int *a, int *b){
    int temp;
    if (*a > *b)
        return *a;
    else
        return *b;
}
