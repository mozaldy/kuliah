/* Melakukan konversi valuta asing, misalnya mata uang dolar US ke mata uang Rp,
dimana satu dolar sama dengan Rp 11.090 ,-
Input : uang dalam US dolar
Proses : uang_rupiah = uang_dolar * 11090
Output : uang rupiah */
#include <stdio.h>

void main(){
    int usd, idr;
    printf("Program konversi mata uang USD ke IDR \n");
    printf("USD: ");
    scanf("%d", &usd);
    idr = usd * 11000;
    printf("IDR: %d\n", idr);
}