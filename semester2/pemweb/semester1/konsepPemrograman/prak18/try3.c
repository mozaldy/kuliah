#include <stdio.h>
#define ORDO 2
#define MAX 5

int count_matrix = 1, baris, kolom;

void pengisi(int x[baris][kolom]);
void pengoutput(int x[baris][kolom]);

void main()
{
    do
    {
        printf("Input ordo matriks, max 5: ");
        scanf("%d x %d", &baris, &kolom);
        getchar();
    }while(baris > MAX || kolom > MAX);
    int a[baris][kolom], b[baris][kolom], c[baris][kolom];

    pengisi(a);
    pengisi(b);

    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    pengoutput(a);
    printf("+\n");
    pengoutput(b);
    printf("=\n");
    pengoutput(c);
}

void pengisi(int x[baris][kolom])
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            printf("Isi ordo matriks ke-%d[%d, %d]: ", count_matrix, i, j);
            scanf("%d", &x[i][j]);
            getchar();
        }
    }
    count_matrix++;
    printf("\n");
}

void pengoutput(int x[baris][kolom])
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}