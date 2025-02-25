#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    int no;
    char name[50];
    char value;
} Students;

void selection(Students *, int);
void insertion(Students *, int);
void input_array(Students *);

int print_array(Students *);
int main_menu(Students *);

int main() {
    int choice;
    Students array[MAX];
    input_array(array);

    do {
        print_array(array);
        choice = main_menu(array);
    } while (choice != 3);

    return 0;
}

void input_array(Students *array) {
    int jumlah_siswa;
    printf("Berapa siswa yang akan diinput: ");
    scanf("%d", &jumlah_siswa);
    printf("Enter data for %d students:\n", &jumlah_siswa);
    for (int i = 0; i < MAX; i++) {
        printf("Student %d:\n", i + 1);
        printf("No: ");
        scanf("%d", &array[i].no);
        printf("Name: ");
        scanf("%s", array[i].name);
        printf("Value: ");
        scanf(" %c", &array[i].value);
    }
}

int main_menu(Students *array) {
    int choice;
    int order;
    printf("\nMENU METODE SORTING\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Keluar\n");
    printf("Pilihan anda [1/2/3]: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nMENU METODE SORTING\n");
            printf("1. Ascending\n");
            printf("2. Descending\n");
            printf("Pilihan anda [1/2]: ");
            scanf("%d", &order);

            switch (order) {
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

            switch (order) {
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

void insertion(Students *arr, int descending) {
    for (int i = 1; i < MAX; i++) {
        Students key = arr[i];
        int j = i - 1;
        for (; j >= 0 && (descending ? strcmp(arr[j].name, key.name) < 0 : strcmp(arr[j].name, key.name) > 0); j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void selection(Students *arr, int descending) {
    for (int i = 0; i < MAX; i++) {
        int min = i;
        for (int j = i + 1; j < MAX; j++) {
            if (descending ? strcmp(arr[j].name, arr[min].name) < 0 : strcmp(arr[j].name, arr[min].name) > 0) {
                min = j;
            }
        }
        Students temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int print_array(Students *arr) {
    printf("Array:\n");
    for (int i = 0; i < MAX; i++)
        printf("No: %d, Name: %s, Value: %c\n", arr[i].no, arr[i].name, arr[i].value);
    printf("\n");
    return 0;
}
