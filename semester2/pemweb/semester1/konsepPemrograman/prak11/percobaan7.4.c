#include <stdio.h>

void main()
{
    int captive = 0;
    while (1)
    {
        if (captive == 0)
        {
            int n, i = 0, nilai, total_nilai = 0, max = 0, min = 99999;
            printf("Input: ");
            scanf("%d", &n);
            for (; i < n; i++)
            {
                printf("Nilai ke-%d: ", i + 1);
                scanf("%d", &nilai);

                if (nilai > max)
                    max = nilai;
                if (nilai < min)
                    min = nilai;
                total_nilai += nilai;
            }

            printf("Min = %d\n", min);
            printf("Max = %d\n", max);
            printf("Rata-rata = %d\n", total_nilai / i);
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