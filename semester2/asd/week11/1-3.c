#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10000

void bubbleSort(int[], int);
void shellSort(int[], int);
void insertionSort(int[], int);
void selectionSort(int[], int);
void printArray(int[]);
void generate_data(int[]);
int mode_urut();
void main_menu(int[]);
void swap(int *a, int *b);

int main() {
  int arr[MAX], arr_backup[MAX];
  srand(time(NULL));
  generate_data(arr);
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
  printf("3. Insertion Sort\n");
  printf("4. Selection Sort\n");
  printf("5. Keluar\n");
  printf("Pilihan anda [1/2/3/4/5]: ");
  scanf("%d", &pilihan);

  start = clock();
  switch (pilihan) {
  case 1:
    bubbleSort(arr, mode_urut());
    break;
  case 2:
    shellSort(arr, mode_urut());
    break;
  case 3:
    insertionSort(arr, mode_urut());
    break;
  case 4:
    selectionSort(arr, mode_urut());
    break;
  case 5:
    exit(0);
    break;

  default:
    printf("Error!\n");
    exit(1);
    break;
  }

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Waktu yang dibutuhkan: %f seconds\n", cpu_time_used);
}

void bubbleSort(int arr[], int is_ascending) {
  int i, j;
  int n = MAX;
  int is_swapped;

  for (i = 0; i < n - 1; i++) {
    is_swapped = 0;
    for (j = 0; j < n - i - 1; j++) {
      if (is_ascending ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        is_swapped = 1;
      }
    }
    if (is_swapped == 0)
      break;
  }
}

void shellSort(int arr[], int is_ascending) {
  int n = MAX;
  int is_swapped;
  for (int gap = n / 2; gap > 0; gap /= 2) {
    is_swapped = 0;
    for (int i = gap; i < n; i += 1) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap &&
                  (is_ascending ? arr[j - gap] > temp : arr[j - gap] < temp);
           j -= gap) {
        arr[j] = arr[j - gap];
        is_swapped = 1;
      }
      arr[j] = temp;
    }
    if (is_swapped == 0)
      break;
  }
}

void insertionSort(int arr[], int is_ascending) {
  for (int i = 1; i < MAX; i++) {
    int key = arr[i], j = i - 1;
    for (; j >= 0 && (is_ascending ? arr[j] < key : arr[j] > key); j--)
      arr[j + 1] = arr[j];
    arr[j + 1] = key;
  }
}

void selectionSort(int arr[], int is_ascending) {
  for (int i = 0; i < MAX; i++) {
    int temp, min = i;
    for (int j = i + 1; j < MAX; j++) {
      if (is_ascending ? arr[j] < arr[min] : arr[j] > arr[min]) {
        min = j;
      }
    }
    swap(&arr[i], &arr[min]);
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
