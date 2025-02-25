    #include <stdio.h>

    void main()
    {
        int menu;
        float angka_pertama, angka_kedua, hasil;
        printf("Menu Perhitungan\n");
        printf("1. Menghitung volume kubus\n");
        printf("2. Menghitung luas lingkaran\n");
        printf("3. Menghitung volume silinder.\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Panjang sisi kubus: ");
            scanf("%f", &angka_pertama);
            hasil = angka_pertama * angka_pertama * angka_pertama;
            printf("Volume Kubus: %.1f\n", hasil);
            break;
        case 2:
            printf("Panjang jari-jari lingkaran: ");
            scanf("%f", &angka_pertama);

            hasil = 3.14 * (angka_pertama * angka_pertama);
            printf("Luas lingkaran: %.1f", hasil);
            break;
        case 3:
            printf("Panjang jari-jari lingkaran: ");
            scanf("%f", &angka_pertama);
            printf("Tinggi silinder: ");
            scanf("%f", &angka_kedua);

            hasil = 3.14 * (angka_pertama * angka_pertama) * angka_kedua;

            printf("Volume silinder: %.1f\n", hasil);
            break;

        default:
            printf("Operator tidak valid!\n");
            break;
        }
    }
