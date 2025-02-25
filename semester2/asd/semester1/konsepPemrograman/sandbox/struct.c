#include <stdio.h>

void main()
{
    struct mahasiswa
    {
        long nrp;
        char nama[255];
        char asal[255];
    };

    struct mahasiswa awp = {3123600027, "Ahmad Zidan WP", "Sidoarjo"};
    awp.nrp = 3123600029;
    struct mahasiswa aldy = {3123600011, "Mohammad Rizaldy Ramadhan", "Banyuwangi"};
    struct mahasiswa zaidan = {3123600021, "Zaidan gaming", "Sidoarjo"};

    // struct mahasiswa d4ita[30] = {awp, aldy, zaidan};
    printf("Nama mahasiswa: %s \n", awp.nama);
    printf("NRP: %li \n", awp.nrp);
    printf("Asal: %s \n", awp.asal);

    printf("Nama mahasiswa: %s \n", zaidan.nama);
    printf("NRP: %li \n", zaidan.nrp);
    printf("Asal: %s \n", zaidan.asal);

    printf("Nama mahasiswa: %s \n", aldy.nama);
    printf("NRP: %li \n", aldy.nrp);
    printf("Asal: %s \n", aldy.asal);

    // for (size_t i = 0; i < 3; i++)
    // {
    // }
}