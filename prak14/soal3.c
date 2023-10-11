#include <stdio.h>
void ubah(int);
main()
{
    int x;
    printf("Masukkan nilai x : ");
    scanf("%d", &x);
    ubah(x);
    printf("x = %d\n", x);
}
void ubah(int y)
{
    y = 85;
}