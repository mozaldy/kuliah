#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main_menu(int *);
void generate_int(int *);
void swap(int *, int *);

void sequential_search(int *, int, int);
void binary_search(int *, int, int, int);

void quick_sort(int *, int, int);
int partition(int *, int, int);

int jumlah_data, jumlah_ditemukan;

int main() {
  printf("Jumlah data: ");
  scanf("%d", &jumlah_data);
  int array[jumlah_data], array_backup[jumlah_data], user_input;
  generate_int(array);
  memcpy(array_backup, array, sizeof(int) * jumlah_data);
  do {
    jumlah_ditemukan = 0;
    memcpy(array, array_backup, sizeof(int) * jumlah_data);
    user_input = main_menu(array);
  } while (user_input != 0);
}

int main_menu(int arr[]) {
  int dicari, menu_input;
  clock_t start, end;
  double cpu_time_used;
  printf("Angka yang ingin dicari: ");
  scanf("%d", &dicari);
  printf("Pilih metode pencarian:\n");
  printf("1. Sequential Search Pada unsorted array\n");
  printf("2. Sequential Search Pada sorted array\n");
  printf("3. Binary Search Pada sorted array\n");
  printf("4. Cancel\n");
  printf("Input Pilihan [1/2/3/4]: ");
  scanf("%d", &menu_input);
  start = clock();
  if (menu_input != 1)
    quick_sort(arr, 0, jumlah_data - 1);
  switch (menu_input) {
  case 1:
    sequential_search(arr, dicari, 0);
    break;
  case 2:
    sequential_search(arr, dicari, 1);
    break;
  case 3:
    binary_search(arr, dicari, 0, jumlah_data - 1);
    break;
  case 4:
    return 0;
    break;
  }
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Angka %d ditemukan %d kali.\n", dicari, jumlah_ditemukan);
  printf("Waktu yang diperlukan: %f\n", cpu_time_used);
  return 1;
}

void sequential_search(int arr[], int n, int sorted) {
  bool found = false;
  printf("Indices found: ");
  for (int i = 0; i < jumlah_data; i++) {
    if (arr[i] == n) {
      found = true;
      jumlah_ditemukan++;
    }
    if (sorted && arr[i] > n)
      break;
  }
  printf("\n");
  if (!found)
    printf("Angka %d tidak ditemukan dalam array!\n", n);
}

void binary_search(int arr[], int n, int start, int end) {
  if (start > end)
    return;

  int middle = (start + end) / 2;
  if (arr[middle] == n) {
    jumlah_ditemukan++;
    int left = middle - 1;
    int right = middle + 1;
    while (left >= start && arr[left] == n) {
      jumlah_ditemukan++;
      left--;
    }
    while (right <= end && arr[right] == n) {
      jumlah_ditemukan++;
      right++;
    }
    return;
  }

  if (arr[middle] < n)
    binary_search(arr, n, middle + 1, end);
  else
    binary_search(arr, n, start, middle - 1);
}

void generate_int(int arr[]) {
  for (int i = 0; i < jumlah_data; i++)
    arr[i] = rand() / 10000000;
}

void quick_sort(int *arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi);
    quick_sort(arr, pi + 1, high);
  }
}

int partition(int *arr, int low, int high) {
  int pivot = arr[low];
  int i = low - 1;
  int j = high + 1;

  while (true) {
    do {
      i++;
    } while (pivot > arr[i]);
    do {
      j--;
    } while (arr[j] > pivot);
    if (i >= j)
      return j;

    swap(&arr[i], &arr[j]);
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
