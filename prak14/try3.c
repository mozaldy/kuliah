#include <stdio.h>
int prima(int);

void main(){
    int input;
    printf("Input: ");
    scanf("%d", &input);
    printf(prima(input) == 1 ? "Prima\n" : "Bukan Prima\n");
}

int prima(int n){
    if (n <= 0)
        return 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
    
}