#include <stdio.h>

void main()
{
    int bilangan = 1, input;
    printf("Input:\n");
    scanf("%d", &input);
    for (; bilangan < input; bilangan += 2)
    {
        if (bilangan % 3 == 0)
            continue;
        printf("%d ", bilangan);
    }
    printf("\n");
}