#include <stdio.h>
#define PI 3.14159f
float radian(int);

void main(){
    int input;
    printf("Derajat: ");
    scanf("%d", &input);
    printf("Radian = %f\n", radian(input));
}

float radian(int n){
    return n * PI / 180.0f;
}