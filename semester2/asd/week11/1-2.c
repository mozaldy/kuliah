#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10000

void bubbleSort(int[], int *, int *, int *, int);
void shellSort(int[], int *, int *, int *, int);
void printArray(int[]);
void generate_data(int[]);
int mode_urut();
void main_menu(int *);
void swap(int *a, int *b);

int main() {
  int arr[MAX], arr_backup[MAX];
  generate_data(arr);
  srand(time(NULL));
  do {
    memcpy(arr_backup, arr, MAX * sizeof(int));
    main_menu(arr_backup);
  } while (1);

  return 0;
}

void main_menu(int arr[]) {
  int comparisons, swaps, movements, pilihan;
  clock_t start, end;
  double cpu_time_used;

  comparisons = swaps = movements = 0;

  printf("\nMENU METODE SORTING\n");
  printf("1. Bubble Sort\n");
  printf("2. Shell Sort\n");
  printf("3. Keluar\n");
  printf("Pilihan anda [1/2/3]\n");
  scanf("%d", &pilihan);

  start = clock();
  switch (pilihan) {
  case 1:
    bubbleSort(arr, &comparisons, &swaps, &movements, mode_urut());
    break;
  case 2:
    shellSort(arr, &comparisons, &swaps, &movements, mode_urut());
    break;
  case 3:
    exit(0);
    break;

  default:
    printf("Error!\n");
    exit(1);
    break;
  }

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("\nSorted Array:\n");

  printf("Jumlah pembandingan: %d\n", comparisons);
  printf("Jumlah penukaran: %d\n", swaps);
  printf("Jumlah pergeseran: %d\n", movements);
  printf("Waktu yang dibutuhkan: %f seconds\n", cpu_time_used);
}

void bubbleSort(int arr[], int *comparisons, int *swaps, int *movements,
                int is_ascending) {
  int i, j, temp;
  int n = MAX;
  int is_swapped;

  for (i = 0; i < n - 1; i++) {
    is_swapped = 0;
    for (j = 0; j < n - i - 1; j++) {
      (*comparisons)++;
      if (is_ascending ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
        (*swaps)++;
        swap(&arr[j], &arr[j + 1]);
        is_swapped = 1;
      }
    }
    (*movements)++;

    if (is_swapped == 0)
      break;
  }
}

void shellSort(int arr[], int *comparisons, int *swaps, int *movements,
               int is_ascending) {
  int n = MAX;
  int is_swapped;

  for (int gap = n / 2; gap > 0; gap /= 2) {
    is_swapped = 0;
    for (int i = gap; i < n; i += 1) {
      int temp = arr[i];
      int j;
      (*movements)++;
      for (j = i; j >= gap &&
                  (is_ascending ? arr[j - gap] > temp : arr[j - gap] < temp);
           j -= gap) {
        (*comparisons)++;
        (*swaps)++;
        arr[j] = arr[j - gap];
        is_swapped = 1;
      }
      arr[j] = temp;
    }

    if (is_swapped == 0)
      break;
  }
}

void generate_data(int x[]) {
  for (int i = 0; i < MAX; i++)
    x[i] = rand() / 10000000;
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

void printArray(int arr[]) {
  int i;
  for (i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
