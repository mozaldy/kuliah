#include <stdio.h>

#define MAX 10

void selection(int *, int);
void insertion(int *, int);

int print_array(int *);
int main_menu(int *);

int main()
{
    int choice;
    int array[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    do
    {
        print_array(array);
        choice = main_menu(array);
    } while (choice != 3);

    return 0;
}

int main_menu(int *array)
{
    int choice;
    int order;
    printf("\nMENU METODE SORTING\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Keluar\n");
    printf("Pilihan anda [1/2/3]: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nMENU METODE SORTING\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        printf("Pilihan anda [1/2]: ");
        scanf("%d", &order);

        switch (order)
        {
        case 1:
            insertion(array, 0);
            break;
        case 2:
            insertion(array, 1);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
        }
        break;
    case 2:
        printf("\nMENU METODE SORTING\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        printf("Pilihan anda [1/2]: ");
        scanf("%d", &order);

        switch (order)
        {
        case 1:
            selection(array, 0);
            break;
        case 2:
            selection(array, 1);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
        }
        break;
    case 3:
        printf("Terima kasih!\n");
        return 3;
        break;
    default:
        printf("Pilihan tidak valid.\n");
        break;
    }
}

void insertion(int *arr, int descending)
{
    for (int i = 1; i < MAX; i++)
    {
        int key = arr[i], j = i - 1;
        for (; j >= 0 && (descending ? arr[j] < key : arr[j] > key); j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void selection(int *arr, int descending)
{
    for (int i = 0; i < MAX; i++)
    {
        int temp, min = i;
        for (int j = i + 1; j < MAX; j++)
        {
            if (descending ? arr[j] < arr[min] : arr[j] > arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int print_array(int *arr)
{
    printf("Array:\n");
    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}