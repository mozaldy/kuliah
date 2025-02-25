#include <stdio.h>

void main()
{
    int captive = 0;
    while (1)
    {
        if (captive == 0)
        {
            int input;
            printf("Input angka: ");
            scanf("%d", &input);
            for (int i = 1; i <= input; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    printf("%d ", i);
                }
                printf("\n");
            }
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