#include <stdio.h>

void main()
{
    int gaji, gaji_pokok, hari_bekerja, tunjangan_pasangan, jumlah_anak, tunjangan_anak, thr, pajak, transport, asuransi;
    printf("Gaji pokok: ");
    scanf("%d", &gaji_pokok);
    printf("Hari bekerja: ");
    scanf("%d", &hari_bekerja);
    printf("Jumlah anak: ");
    scanf("%d", &jumlah_anak);
    tunjangan_pasangan = gaji_pokok * 0.1;
    tunjangan_anak = gaji_pokok * 0.05 * jumlah_anak;
    thr = hari_bekerja / 365 * 5000;
    pajak = gaji_pokok * 0.15 * -1;
    transport = hari_bekerja * 3000;
    asuransi = -20000;
    gaji = gaji_pokok + tunjangan_pasangan + tunjangan_anak + thr + pajak + transport + asuransi; 
    printf("Tunjangan pasangan: %d\n", tunjangan_pasangan);
    printf("Tunjangan anak: %d\n", tunjangan_anak);
    printf("THR: %d\n", thr);
    printf("Pajak: %d\n", pajak);
    printf("Transport: %d\n", transport);
    printf("Asuransi: %d\n", asuransi);
    printf("Total gaji: %d\n", gaji);
}