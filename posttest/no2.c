#include <stdio.h>

void main()
{
    int kaos = 0, kemeja = 0, training = 0, barang_total = 0, diskon;
    float harga_total = 0;
    printf("Pembelian: \n");
    printf("Kaos: \n");
    scanf("%d", &kaos);
    printf("Kemeja Batik: \n");
    scanf("%d", &kemeja);
    printf("Celana Training: \n");
    scanf("%d", &training);
    barang_total = kaos + kemeja + training;
    if (kaos > 0)
        harga_total += kaos * 100000;

    if (kemeja > 0)
        harga_total += kemeja * 150000;

    if (training > 0)
    {
        harga_total += training * 175000;
    }
    if (barang_total == 2)
    {
        diskon = harga_total * 0.15;
    }
    else if (barang_total >= 3){
        diskon = harga_total * 0.20;
    }
    else if (barang_total >= 5 * 0.35){
        diskon = harga_total * 0.35;

    }
    harga_total -= diskon;
    printf("%.1f\n", harga_total);
}
