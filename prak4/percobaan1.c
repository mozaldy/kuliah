#include <stdio.h>

void main(){
    float celcius, fahrenheit;
    printf("Input suhu dalam Celcius: ");
    scanf("%f", &celcius);
    fahrenheit = celcius * 1.8 + 32;
    printf("Fahrenheit: %.2f\n", fahrenheit);
}