#include <stdio.h>

void main()
{
    char input;
    
    while(input != 'X'){
        printf("%c", input);
        scanf("%c", &input);
    }
}