#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long long int iterasi(int);
long long int rekursi(int);
long long int rekursi_tail(int, int);

void menu();

int main()
{
    time_t t1, t2;
    long long int hasil;
    int n, choice;
    printf("Input n: ");
    scanf("%d", &n);
    menu();
    scanf("%d", &choice);
    time(&t1);
    switch (choice)
    {
    case 1:
        hasil = iterasi(n);
        break;
    case 2:
        hasil = rekursi(n);
        break;
    case 3:
        hasil = rekursi_tail(n -1, n);
        break;
    default:
        printf("Pilihan tidak valic!\n");
        break;
    }
    printf("Hasil dari %d! = %lld.\n", n, hasil);
    time(&t2);
    unsigned long waktu = t2 - t1;
    printf("waktu komputasi: %ld\n", waktu);
}

void menu()
{
    printf("1. Iterasi\n");
    printf("2. Rekursi\n");
    printf("3. Rekursi Tail\n");
    printf("Input pilihan anda: ");
}

long long int iterasi(int n)
{
    int hasil = n;
    n--;
    for (; n != 0; n--)
        hasil *= n;
    return hasil;
}

long long int rekursi(int n)
{
    if (n == 1)
        return 1;
    return n * rekursi(n - 1);
}
long long int rekursi_tail(int n, int a)
{
    if (n < 0)
        return 0;
    else if (n == 0 || n == 1)
        return a;
    else
        return rekursi_tail(n - 1, n * a);
}
