#include<stdio.h>
#include<math.h>
#define PI 3.14159
float radian(int);

void main(){
    int panjangAB, sudutBAC; 
    float hasil;

    printf("Sudut BAC: ");
    scanf("%d", &sudutBAC);
    printf("Panjang AB(m): ");
    scanf(" %d", &panjangAB);
    hasil = tan(radian(sudutBAC)) * panjangAB;
    printf("Hasil = %.0f\n", hasil);


}
float radian(int n){
    return n * PI / 180.0;
}