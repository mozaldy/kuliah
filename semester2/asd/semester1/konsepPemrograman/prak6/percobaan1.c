// Buat program yang meminta masukan bilangan bulat dari pengguna. Jika pengguna memasukkan 1, 
// program menampilkan ’Minggu’; jika pengguna memasukkan 2, program menampilkan ’Senin’, 
// dan seterusnya sampai dengan ’Sabtu’. Jika pengguna memasukkan nilai di luar jangkauan 1 sampai dengan 7, 
// program menuliskan ’Hari tidak Valid’
#include <stdio.h>

void main(){
    int suhu;
    printf("Input suhu: ");
    scanf("%d", &suhu);

    if(suhu < 0){
        printf("Benda berbentuk padat\n");
    }
    else if(suhu >= 0 && suhu <= 100){
        printf("Benda berbentuk cair\n");
    }
    else{
        printf("Benda berbentuk gas\n");
    }
}