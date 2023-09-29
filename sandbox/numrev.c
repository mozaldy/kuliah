#include <stdio.h>

void main(){
    int input, reversed = 0, digit = 0, temp;
    printf("Input angka: ");
    scanf("%d", &input);

    temp = input;

    while (temp > 0)
    {
        temp /= 10;
        digit++;
    }
    

    while (input > 0)
    {
        int exp = 0;
        for (int i = 0; i < digit; i++)
        {
            exp
        }
        
        reversed += input % 10;
        input /= 10;
    }
    printf("%d\n", reversed);
    
}