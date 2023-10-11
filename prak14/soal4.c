#include <stdio.h>
int validasi_tanggal(int, int, int);
void main()
{
    int dd, mm, yyyy;
    printf("Tanggal: ");
    scanf("%d", &dd);
    printf("Bulan: ");
    scanf("%d", &mm);
    printf("Tahun: ");
    scanf("%d", &yyyy);
    printf(validasi_tanggal(dd, mm, yyyy) == 1 ? "Tanggal Valid.\n" : "Tanggal tidak valid.\n");
}
int validasi_tanggal(int dd, int mm, int yyyy)
{
    int hari_feb;
    if (yyyy % 100 == 0)
    {
        if (yyyy % 400 == 0)
            hari_feb = 29;
        else
            hari_feb = 28;
    }
    else if (yyyy % 4 == 0)
        hari_feb = 29;
    else
        hari_feb = 28;

    if (dd < 1 || mm < 1)
        return 0;

    if (mm == 2)
        return dd <= hari_feb ? 1 : 0;
    else if (mm <= 7)
    {
        if (mm % 2 == 0)
            return dd <= 30 ? 1 : 0;
        else
            return dd <= 31 ? 1 : 0;
    }
    else if (mm <= 12)
    {
        if (mm % 2 == 0)
            return dd <= 31 ? 1 : 0;
        else
            return dd <= 30 ? 1 : 0;
    }

}