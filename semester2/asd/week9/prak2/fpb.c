#include <stdio.h>

int fpb(int a, int b);

int main(){
    int a, b;
    printf("Input angka a: ");
    scanf("%d", &a);
    printf("Input angka b: ");
    scanf("%d", &b);
    printf("%d\n", fpb(a, b));
}

int fpb(int a, int b){
    if (b == 0)
        return a;
    else
        return fpb(b, a % b);
}