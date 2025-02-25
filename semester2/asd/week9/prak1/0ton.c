#include <stdio.h>

int nillton(int);

int val = 0;

int main()
{
    int n;
    printf("Input n: ");
    scanf("%d", &n);

    nillton(n);
}

int nillton(int n)
{
    printf("%d\n", val);
    if (n == val)
        exit(0);
    val++;
    nillton(n);
}