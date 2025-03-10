#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int no, nilai;
  char nama[50];
} siswa;

typedef siswa data;

int jumlah_data;
int sort_by;
bool is_ascending;

int main_menu(data *);
int set_sortby();
bool set_isascending();
bool should_swap(data *, data *);
void swap(data *, data *);
void input_data(data *);
void print_data(data *);

void insertion_sort(data *);
void selection_sort(data *);
void bubble_sort(data *);
void shell_sort(data *);
void quick_sort(data *, int, int);
int partition(data *, int, int);
void merge_sort(data *, int, int);
void merge(data *, int, int, int);

int main(int argc, char *argv[]) {
  printf("Masukkan jumlah data: ");
  scanf("%d", &jumlah_data);

  data array[jumlah_data], backup[jumlah_data];

  input_data(array);

  memcpy(backup, array, jumlah_data * sizeof(data));
  int menu = 0;
  while (menu != 7) {
    memcpy(array, backup, jumlah_data * sizeof(data));
    menu = main_menu(array);
    print_data(array);
  }
  printf("Keluar dari program\n");
  return 0;
}

void input_data(data *d) {
  for (int i = 0; i < jumlah_data; i++) {
    printf("Data ke-%d\n", i + 1);
    printf("No: ");
    scanf("%d", &d[i].no);
    printf("Nama: ");
    scanf("%s", d[i].nama);
    printf("Nilai: ");
    scanf("%d", &d[i].nilai);
  }
}

void print_data(data *d) {
  for (int i = 0; i < jumlah_data; i++) {
    printf("Data ke-%d\n", i + 1);
    printf("No: %d\n", d[i].no);
    printf("Nama: %s\n", d[i].nama);
    printf("Nilai: %d\n", d[i].nilai);
  }
}

int main_menu(data array[]) {
  int pilihan;
  printf("MENU METODE SORTING\n");
  printf("1. Insertion Sort\n");
  printf("2. Selection Sort\n");
  printf("3. Bubble Sort\n");
  printf("4. Shell Sort\n");
  printf("5. Quick Sort Recursive\n");
  printf("6. Merge Sort Recursive\n");
  printf("7. Keluar\n");
  printf("Pilihan anda [1/2/3/4/5/6/7]: ");
  scanf("%d", &pilihan);

  if (pilihan != 7) {
    sort_by = set_sortby();
    is_ascending = set_isascending();
  }

  switch (pilihan) {
  case 1:
    printf("\nINSERTION SORT\n");
    insertion_sort(array);
    break;
  case 2:
    printf("\nSELECTION SORT\n");
    selection_sort(array);
    break;
  case 3:
    printf("\nBUBBLE SORT\n");
    bubble_sort(array);
    break;
  case 4:
    printf("\nSHELL SORT\n");
    shell_sort(array);
    break;
  case 5:
    printf("\nQUICK SORT\n");
    quick_sort(array, 0, jumlah_data);
    break;
  case 6:
    printf("\nMERGE SORT\n");
    merge_sort(array, 0, jumlah_data - 1);
    break;
  case 7:
    break;
  default:
    printf("Pilihan tidak valid. ulangi lagi!\n");
    break;
  }
  return pilihan;
}

int set_sortby() {
  int pilihan;
  bool valid;
  do {
    printf("1. No\n");
    printf("2. Nama\n");
    printf("3. Nilai\n");
    printf("Pilihan anda [1/2/3]: ");
    scanf("%d", &pilihan);
    valid = pilihan >= 1 && pilihan <= 3;
    if (!valid)
      printf("Pilihan tidak valid\n");
  } while (!valid);
  return pilihan;
}

bool set_isascending() {
  int pilihan;
  bool valid;
  do {
    printf("Mode pengurutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan anda [1/2]: ");
    scanf("%d", &pilihan);
    valid = pilihan == 1 || pilihan == 2;
    if (!valid)
      printf("Pilihan tidak valid\n");
  } while (!valid);
  return pilihan == 1; // Return true if ascending
}

bool should_swap(data *a, data *b) {
  bool result;
  switch (sort_by) {
  case 1:
    result = is_ascending ? a->no > b->no : a->no < b->no;
    break;
  case 2:
    result = is_ascending ? strcmp(a->nama, b->nama) > 0
                          : strcmp(a->nama, b->nama) < 0;
    break;
  case 3:
    result = is_ascending ? a->nilai > b->nilai : a->nilai < b->nilai;
    break;
  }
  return result;
}

void swap(data *a, data *b) {
  data temp = *a;
  *a = *b;
  *b = temp;
}

void insertion_sort(data *arr) {
  for (int i = 1; i < jumlah_data; i++) {
    data key = arr[i];
    int j = i - 1;
    for (; j >= 0 && should_swap(&arr[j], &key); j--)
      arr[j + 1] = arr[j];
    arr[j + 1] = key;
  }
}

void selection_sort(data *arr) {
  for (int i = 0; i < jumlah_data; i++) {
    int min = i;
    for (int j = i + 1; j < jumlah_data; j++) {
      if (should_swap(&arr[j], &arr[min]))
        min = j;
    }
    swap(&arr[i], &arr[min]);
  }
}

void bubble_sort(data *arr) {
  for (int i = 0; i < jumlah_data - 1; i++) {
    bool is_swapped = 0;
    for (int j = 0; j < jumlah_data - i - 1; j++) {
      if (should_swap(&arr[j], &arr[j + 1])) {
        swap(&arr[j], &arr[j + 1]);
        is_swapped = 1;
      }
    }
    if (!is_swapped)
      break;
  }
}

void shell_sort(data *arr) {
  for (int gap = jumlah_data / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < jumlah_data; i++) {
      data temp = arr[i];
      int j;
      for (j = i; j >= gap && should_swap(&arr[j - gap], &temp); j -= gap)
        arr[j] = arr[j - gap];
      arr[j] = temp;
    }
  }
}

void quick_sort(data *arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi);
    quick_sort(arr, pi + 1, high);
  }
}

int partition(data *arr, int low, int high) {
  data pivot = arr[low];
  int i = low - 1;
  int j = high + 1;

  while (true) {
    do {
      i++;
    } while (should_swap(&pivot, &arr[i]));
    do {
      j--;
    } while (should_swap(&arr[j], &pivot));
    if (i >= j)
      return j;

    swap(&arr[i], &arr[j]);
  }
}

void merge_sort(data *arr, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void merge(data *arr, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  data L[n1], R[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[m + 1 + i];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (should_swap(&R[j], &L[i])) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
