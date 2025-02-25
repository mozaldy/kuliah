#include <stdio.h>

int c(int);
int s(int);

void main()
{
    int input;
    printf("Masukkan nilai n: ");
    scanf("%d", &input);

        
    printf("Hasil fungsi c = %d \n", c(input));
    printf("Hasil fungsi s = %d \n", s(input));
    printf("\n");
}

int c(int n){
    int hasil = 0;
    for(int i = 0; i <= n; i++){
        if(i == 0){
            hasil += 1;
            continue;
        }
        hasil = 2 * hasil + 1;
    }
    return hasil;
}

int s(int n){
    int hasil = 0;
    for (int i = 0; i <= n; i++)
    {
        if(i == 1){
            hasil = 0;
            continue;
        }
        hasil = hasil + i - 1;
    }
    return hasil;
    
}

// int c(int n)
// {
//     if (n == 0)
//         return 1;
//     return 2 * n + 1;

// }

// int s(int n)
// {
//     if (n == 0)
//         return 0;
//     return hasil_sebelum + n - 1;
// }