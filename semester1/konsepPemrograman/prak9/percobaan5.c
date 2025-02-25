#include <stdio.h>

int main()
{
    int n, pembagi = 0;
    printf("Angka: ");
    scanf("%d", &n);

    for (int i = 2; i < n / 2; i++){
        if (n % i == 0)
            pembagi++;
    }
    if (n < 2)
        pembagi++;
    printf((pembagi == 0 ? "Angka prima\n" : "Bukan angka prima\n"));
}