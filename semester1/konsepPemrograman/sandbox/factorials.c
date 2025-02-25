#include <stdio.h>

void main(){
    int input, factorial = 1;
    printf("Program factorial, input angka: ");
    scanf("%d", &input);
    for (int i = 1; i <= input; i++)
    {
        factorial *= i;
    }
    printf("Hasil dari %d factorial adalah %d\n", input, factorial);
    
}