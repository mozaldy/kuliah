#include <stdio.h>

void main()
{
    int captive = 0;
    while (1)
    {
        if (captive == 0)
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

        printf("apakah anda ingin keluar (y/t)? ");
        char menu;
        scanf(" %c", &menu);
        if (menu == 'y')
        {
            printf("Keluar dari program.\n");
            break;
        }
        else if (menu == 't')
            captive = 0;
        else
        {
            printf("Input tidak valid. coba lagi.\n");
            captive = 1;
        }
    }
}