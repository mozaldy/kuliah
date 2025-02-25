#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 50000

typedef struct {
  int no, nilai;
  char nama[50];
} siswa;

typedef int data;

void bubbleSort(data[], int, int);
void shellSort(data[], int, int);
void insertionSort(data[], int, int);
void selectionSort(data[], int, int);
void mergeSort(data array[], int, int, int);
void merge(data array[], int, int, int, int);
void quickSort(data[], int, int, int);
int partition(data[], int, int, int);
void print_array(data[]);
int mode_urut();
int kategori_urut();
void main_menu(data[]);
void swap(data *a, data *b);
int len(data arr[]);
void generate_data(int[]);

int main() {
  data arr[MAX], arr_backup[MAX];
  srand(time(NULL));
  generate_data(arr);
  do {
    memcpy(arr_backup, arr, MAX * sizeof(data));
    main_menu(arr_backup);
  } while (1);

  return 0;
}

void main_menu(data arr[]) {
  int pilihan, mode, sort_by;
  int left = 0, right;
  right = len(arr) - 1;
  clock_t start, end;
  double cpu_time_used;

  printf("\nMENU METODE SORTING\n");
  printf("1. Bubble Sort\n");
  printf("2. Shell Sort\n");
  printf("3. Insertion Sort\n");
  printf("4. Selection Sort\n");
  printf("5. Merge Sort\n");
  printf("6. Quick Sort\n");
  printf("7. Keluar\n");
  printf("Pilihan anda [1/2/3/4/5/6/7]: ");
  scanf("%d", &pilihan);

  mode = mode_urut();
  sort_by = 1;
  start = clock();
  switch (pilihan) {
  case 1:
    bubbleSort(arr, mode, sort_by);
    break;
  case 2:
    shellSort(arr, mode, sort_by);
    break;
  case 3:
    insertionSort(arr, mode, sort_by);
    break;
  case 4:
    selectionSort(arr, mode, sort_by);
    break;
  case 5:
    mergeSort(arr, left, right, mode);
    break;
  case 6:
    quickSort(arr, left, MAX, mode);
    break;
  case 7:
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

void bubbleSort(data arr[], int is_ascending, int sort_by) {
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

void shellSort(data arr[], int is_ascending, int sort_by) {
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

void insertionSort(data arr[], int is_ascending, int sort_by) {
  for (int i = 1; i < MAX; i++) {
    int key = arr[i], j = i - 1;
    for (; j >= 0 && (is_ascending ? arr[j] < key : arr[j] > key); j--)
      arr[j + 1] = arr[j];
    arr[j + 1] = key;
  }
}

void selectionSort(data arr[], int is_ascending, int sort_by) {
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

int urut(data *a, data *b, int kategori, int is_ascending) {
  for (int i = 0; i < MAX; i++) {
    int temp, min = i;
    for (int j = i + 1; j < MAX; j++) {
      if (is_ascending ? a[j] < b[min] : a[j] > b[min]) {
        min = j;
      }
    }
    swap(&a[i], &b[min]);
  }
}

int mode_urut() {
  int pilihan;
  printf("\nMENU METODE SORTING\n");
  printf("1. Ascending\n");
  printf("2. Descending\n");
  printf("Pilihan anda [1/2]: ");
  scanf("%d", &pilihan);
  if (pilihan == 2)
    return 0;
  return 1;
}

void print_array(data *arr) {
  printf("Data:\n");
  for (int i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void swap(data *a, data *b) {
  data temp = *a;
  *a = *b;
  *b = temp;
}

int len(data arr[]) { return MAX; }

void mergeSort(data array[], int left, int right, int mode) {
  if (left < right) {
    int median = (left + right) / 2;
    mergeSort(array, left, median, mode);
    mergeSort(array, median + 1, right, mode);
    merge(array, left, median, right, mode);
  }
}
void merge(data array[], int left, int median, int right, int mode) {
  int left1, left2, right1, right2, i, j;
  data temp_array[right];
  left1 = left;
  right1 = median;
  left2 = median + 1;
  right2 = right;
  i = left;
  while (left1 <= right1 && left2 <= right2) {
    if (mode ? array[left1] <= array[left2] : array[left1] >= array[left2]) {
      temp_array[i] = array[left1];
      left1++;
    } else {
      temp_array[i] = array[left2];
      left2++;
    }
    i++;
  }
  while (left1 <= right1) {
    temp_array[i] = array[left1];
    i++;
    left1++;
  }
  while (left2 <= right2) {
    temp_array[i] = array[left2];
    i++;
    left2++;
  }
  j = left;
  while (j <= right) {
    array[j] = temp_array[j];
    j++;
  }
}
void quickSort(data array[], int p, int r, int mode) {
  if (p < r) {
    int q = partition(array, p, r, mode);
    quickSort(array, p, q - 1, mode);
    quickSort(array, q + 1, r, mode);
  }
}
int partition(data array[], int p, int r, int mode) {
  data x = array[p];
  int i = p, j = r;
  while (i <= j) {
    while (array[i] < x)
      i++;
    while (array[j] > x)
      j--;
    if (mode ? i < j : i > j) {
      swap(&array[i], &array[j]);
      i++;
      j--;
    } else {
      return j;
    }
  }
}

void generate_data(int x[]) {
  for (int i = 0; i < MAX; i++)
    x[i] = rand() / 10000000;
}
