#include <stdio.h>

void main()
{
    char input;
    
    while(1){
        scanf("%c", &input);
        if (input == '\n')
            break;
        printf("%c", input);
    }
    printf("\n");
}   