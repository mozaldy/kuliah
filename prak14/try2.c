#include <stdio.h>

long factorial(int);
void main(){
    int input;
    printf("Input: ");
    scanf("%d", &input);
    if(input < 0)
        printf("Factorial dari %d tidak terdefinisi.\n", input);
    else
        printf("Factorial dari %d adalah %ld\n", input, factorial(input));
}
long factorial(int n){
    int hasil = 1;
    while (n > 0){
        hasil *= n;
        n--;
    }
    return hasil;
}