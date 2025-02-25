// Buat program yang meminta masukan bilangan bulat dari pengguna. Jika pengguna memasukkan 1, 
// program menampilkan ’Minggu’; jika pengguna memasukkan 2, program menampilkan ’Senin’, 
// dan seterusnya sampai dengan ’Sabtu’. Jika pengguna memasukkan nilai di luar jangkauan 1 sampai dengan 7, 
// program menuliskan ’Hari tidak Valid’
#include <stdio.h>

void main(){
    int angka;
    printf("Masukkan angka: ");
    scanf("%d", &angka);
    if (angka < 1 || angka > 7){
        printf("Hari tidak Valid\n");
    }
    else{
        if (angka == 1)
            printf("Senin\n");
        else if(angka == 2)
            printf("Selasa\n");
        else if(angka == 3)
            printf("Rabu\n");
        else if(angka == 4)
            printf("Kamis\n");
        else if(angka == 5)
            printf("Jumat\n");
        else if(angka == 6)
            printf("Sabtu\n");
        else
            printf("Minggu\n");
    }
}