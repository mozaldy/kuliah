#include <stdio.h>

void main()
{
    int n, i = 0, nilai, max = 0, min = 99999;
    float total_nilai = 0;
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
    float rata = total_nilai / i;
    printf("Rata-rata = %.1f\n", rata);
    
    
}