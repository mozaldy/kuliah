#include <stdio.h>

void main(){
    int celcius, fahrenheit;
    printf("Input suhu dalam Celcius: ");
    scanf("%d", &celcius);
    fahrenheit = celcius * 1.8 + 32;
    printf("Fahrenheit: %d\n", fahrenheit);
}