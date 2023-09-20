#include <stdio.h>

void main()
{
    int bil1, bil2, bil3, temp;
    printf("Masukkan bilangan 1: ");
    scanf("%d", &bil1);
    printf("Masukkan bilangan 2: ");
    scanf("%d", &bil2);
    printf("Masukkan bilangan 3: ");
    scanf("%d", &bil3);
    if (bil3 < bil2){
        temp = bil3;
        bil3 = bil2;
        bil2 = temp;
    }

    if (bil3 < bil1){
        temp = bil3;
        bil3 = bil1;
        bil1 = temp;
    }

    if (bil2 < bil1){
        temp = bil2;
        bil2 = bil1;
        bil1 = temp;
    }



    printf("Bilangan setelah diurutkan: %d, %d, %d\n", bil1, bil2, bil3);
}
