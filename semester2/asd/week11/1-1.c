#include <stdio.h>

#define MAX 10

void bubbleSort(int[], int *, int *, int *, int is_ascending);
void shellSort(int[], int *, int *, int *, int is_ascending);
void printArray(int[]);

int mode_urut();
int main_menu();

int main() { main_menu(); }

int main_menu() {
  int arr[MAX] = {64, 34, 25, 12, 22, 11, 90, 0, 1, 100};
  int arr2[MAX] = {64, 34, 25, 12, 22, 11, 90, 0, 1, 100};
  int comparisons, swaps, movements;

  printf("Array sebelum diurutkan: \n");
  printArray(arr);

  comparisons = swaps = movements = 0;
  bubbleSort(arr, &comparisons, &swaps, &movements, mode_urut());
  printf("\nBubble Sort:\n");
  printf("Array setelah diurutkan: \n");
  printArray(arr);
  printf("Jumlah pembandingan: %d\n", comparisons);
  printf("Jumlah penukaran: %d\n", swaps);
  printf("Jumlah pergeseran: %d\n", movements);

  printf("\nArray sebelum diurutkan: \n");
  printArray(arr2);

  comparisons = swaps = movements = 0;
  shellSort(arr2, &comparisons, &swaps, &movements, mode_urut());
  printf("\nShell Sort:\n");
  printf("Array setelah diurutkan: \n");
  printArray(arr2);
  printf("Jumlah pembandingan: %d\n", comparisons);
  printf("Jumlah penukaran: %d\n", swaps);
  printf("Jumlah pergeseran: %d\n", movements);

  return 0;
}

void bubbleSort(int arr[], int *comparisons, int *swaps, int *movements,
                int is_ascending) {
  int i, j, temp;
  int n = MAX;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      (*comparisons)++;
      if (is_ascending ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
        (*swaps)++;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
    (*movements)++;
    printf("Iterasi %d:\n", i + 1);
    printArray(arr);
  }
}

void shellSort(int arr[], int *comparisons, int *swaps, int *movements,
               int is_ascending) {
  int n = MAX;
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i += 1) {
      int temp = arr[i];
      int j;
      (*movements)++;
      for (j = i;
           j >= gap && is_ascending ? arr[j - gap] > temp : arr[j - gap] < temp;
           j -= gap) {
        (*comparisons)++;
        (*swaps)++;
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
    printf("Gap = %d:\n", gap);
    printArray(arr);
  }
}

void printArray(int arr[]) {
  int i;
  for (i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int mode_urut() {
  int order;
  printf("\nMENU METODE SORTING\n");
  printf("1. Ascending\n");
  printf("2. Descending\n");
  printf("Pilihan anda [1/2]: ");
  scanf("%d", &order);
  if (order == 2)
    return 0;
  return 1;
}
