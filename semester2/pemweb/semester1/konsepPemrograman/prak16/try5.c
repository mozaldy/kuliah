#include <stdio.h>

int masukan(int);
int average(int, int);

void main(){
    int count, total;
    printf("Berapa kali input angka: ");
    scanf("%d", &count);
    total = masukan(count);
    printf("Rata-rata adalah %d\n", average(count, total));
}

int masukan(int count){
    int angka, total = 0;
    for (int i = 0; i < count; i++)
    {
        printf("Input angka: ");
        scanf("%d", &angka);
        getchar();
        total += angka;
    }
    return total;
    
}
int average(int count, int total){
    return total / count;
}