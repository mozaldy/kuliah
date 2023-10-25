#include <stdio.h>

void main()
{
    int array[] = {1, 2, 3, 4, 5, 5, 5, 5};
    int len = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", array[i]);
    }

    printf("Length of array: %d\n", len);
}
