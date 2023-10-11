#include <stdio.h>
float konversi_suhu(float, char, char);

void main()
{
    float input, hasil;
    char asal, tujuan;
    printf("Input: ");
    scanf("%f", &input);
    getchar();
    printf("Asal: ");
    asal = getchar();
    getchar();
    printf("Tujuan: ");
    tujuan = getchar();
    hasil = konversi_suhu(input, asal, tujuan);
    printf("Hasil konversi %g %c adalah %g %c\n", input, asal, hasil, tujuan);
}

float konversi_suhu(float n, char asal, char tujuan)
{
    switch (asal)
    {
    case 'C':
        switch (tujuan)
        {
        case 'F':
            return n * 9 / 5 + 32;
            break;
        case 'R':
            return n * 4 / 5;
            break;

        default:
            break;
        }
        break;
    case 'F':
        switch (tujuan)
        {
        case 'C':
            return (n - 32) * 5 / 9;
            break;
        case 'R':
            return (n - 32) * 4 / 9;
            break;

        default:
            break;
        }
        break;
    case 'R':
        switch (tujuan)
        {
        case 'C':
            return n * 5 / 4;
            break;
        case 'F':
            return (n * 9 / 4) + 32;
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
}