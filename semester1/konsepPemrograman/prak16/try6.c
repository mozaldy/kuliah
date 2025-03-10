#include <stdio.h>

int f_to_i(int);
float i_to_cm(int);
float c_to_m(float);

void main(){
    int input;
    float hasil;
    printf("Konversi dari kaki ke m\nInput kaki: ");
    scanf("%d", &input);
    hasil = c_to_m(i_to_cm(f_to_i(input)));
    printf("%g\n", hasil);

}

int f_to_i(int input){
    return input * 12;
}
float i_to_cm(int input){
    return input * 2.54;
}
float c_to_m(float input){
    return input / 100;
}