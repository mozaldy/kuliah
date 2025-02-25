#include <stdio.h>

void main()
{
    int abc[3][2] = {{1, 3},
                 {3, 5},
                 {6, 8}};

    for (int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++){
            printf("%d ", abc[i][j]);
        }
        printf("\n");
    }
}