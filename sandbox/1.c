#include <stdio.h>

void main(){
    int j = 2, temp, b = 1;
    for (int i = 0; i < 10; i++)
    {
        temp = i % 2;
        switch (temp)
        {
        case 0:
            j = j + ++b; 
            break;
        case 1:
            j = j + b++; 
            break;
        }
        printf("%d \n", j);
    }   
}