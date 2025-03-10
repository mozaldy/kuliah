#include <stdio.h>

void main(){
    int tiket, harga;
    printf("Jumlah tiket yang mau dibeli: ");
    scanf("%d", &tiket);

    harga = tiket * 50000;
    harga = harga - 50000 * (tiket / 3); 
    
    printf("Harga: %d\n", harga);
}