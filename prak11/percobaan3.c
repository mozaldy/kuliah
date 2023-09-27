#include <stdio.h>

void main()
{
    int bilangan = 1, input;
    printf("Input:\n");
    scanf("%d", &input);
    for (; bilangan < input; bilangan += 2)
    {
        if (bilangan % 7 == 0 || bilangan % 11 == 0)
            continue;
        if (bilangan >= 100)
            break;
        printf("%d ", bilangan);
    }
    printf("\n");
}