#include <stdio.h>

#define MAX 10

int pergeseran = 0, penyisipan = 0, perbandingan = 0;

int insertion(int *);

int print_array(int *);
void input_array(int *, int);

int main(int argc, char *argv[])
{
    int array[MAX], size;
    printf("Size of array: ");
    scanf("%d", &size);
    input_array(array, size);
    printf("array inisial: ");
    print_array(array);
    insertion(array);
    printf("array akhir: ");
    print_array(array);
    printf("Perbandingan: %d, Pergeseran: %d, Penyisipan: %d\n", perbandingan, pergeseran, penyisipan);
    return 0;
}

void input_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Value ke-%d: ", i);
        scanf("%d", &arr[i]);
    }
}

int insertion(int *arr)
{
    for (int i = 1; i < MAX; i++)
    {
        printf("Iterasi ke-%d: ", i);
        print_array(arr);
        int key = arr[i], j = i - 1;
        perbandingan++;
        for (; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
            pergeseran++;
        }
        penyisipan++;
        arr[j + 1] = key;
    }
    return 0;
}

int print_array(int *arr)
{
    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
