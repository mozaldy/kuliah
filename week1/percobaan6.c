/* Menerima masukan sebuah variabel dengan format int dan char kemudian
menampilkannya kembali */

#include <stdio.h>

int main(){
    int angka;
    char huruf;

    printf("Percobaan 6\n");
    printf("Input angka: \n");
    scanf("%d", &angka);
    printf("Input huruf: \n");
    scanf(" %c", &huruf);
    printf("Angka yang dimasukkan: %d \n", angka);
    printf("Huruf yang dimasukkan: %c \n", huruf);
    return 0;
}