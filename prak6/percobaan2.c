#include <stdio.h>

void main()
{
    int nilai_akademik, nilai_keterampilan, nilai_psikolog;
    printf("Nilai akademik: ");
    scanf("%d", &nilai_akademik);
    printf("Nilai keterampilan: ");
    scanf("%d", &nilai_keterampilan);
    printf("Nilai psikolog: ");
    scanf("%d", &nilai_psikolog);

    int rata_nilai = (nilai_akademik + nilai_keterampilan + nilai_psikolog) / 3;
    if (rata_nilai < 75)
    {
        printf("Anda tidak lolos seleksi!\n");
    }
    else
    {
        if (nilai_akademik > nilai_keterampilan && nilai_akademik > nilai_psikolog)
        {
            printf("Diterima ditempatkan di bagian Administrasi!\n");
        }
        else if (nilai_keterampilan > nilai_akademik && nilai_keterampilan > nilai_psikolog)
        {
            printf("Diterima ditempatkan di bagian Produksi!\n");
        }
        else
        {
            printf("Diterima ditempatkan di bagian Pemasaran!\n");
        }
    }
}