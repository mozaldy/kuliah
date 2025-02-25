#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX 10000

typedef struct {
  int no, nilai;
  char nama[50];
} siswa;

void bubbleSort(siswa[], int, int);
void shellSort(siswa[], int, int);
void insertionSort(siswa[], int, int);
void selectionSort(siswa[], int, int);
void print_array(siswa[]);
int mode_urut();
int kategori_urut();
void main_menu(siswa[]);
void swap(siswa *a, siswa *b);
int urut(siswa *a, siswa *b, int sort_by, int is_ascending);
void input_array(siswa *array);
int len(siswa arr[]);

int main() {
  siswa arr[MAX];
  input_array(arr);
  do {
    print_array(arr);
    main_menu(arr);
  } while (1);

  return 0;
}

void main_menu(siswa arr[]) {
  int pilihan, mode, kategori;

  printf("\nMENU METODE SORTING\n");
  printf("1. Bubble Sort\n");
  printf("2. Shell Sort\n");
  printf("3. Insertion Sort\n");
  printf("4. Selection Sort\n");
  printf("5. Keluar\n");
  printf("Pilihan anda [1/2/3/4/5]: ");
  scanf("%d", &pilihan);

  mode = mode_urut();
  kategori = kategori_urut();

  switch (pilihan) {
  case 1:
    bubbleSort(arr, mode, kategori);
    break;
  case 2:
    shellSort(arr, mode, kategori);
    break;
  case 3:
    insertionSort(arr, mode, kategori);
    break;
  case 4:
    selectionSort(arr, mode, kategori);
    break;
  case 5:
    exit(0);
    break;

  default:
    printf("Error!\n");
    exit(1);
    break;
  }
}

void bubbleSort(siswa arr[], int is_ascending, int sort_by) {
  int i, j;
  int n = len(arr);
  int is_swapped;

  for (i = 0; i < n - 1; i++) {
    is_swapped = 0;
    for (j = 0; j < n - i - 1; j++) {
      if (urut(&arr[j], &arr[j + 1], sort_by, is_ascending)) {
        swap(&arr[j], &arr[j + 1]);
        is_swapped = 1;
      }
    }
    if (is_swapped == 0)
      break;
  }
}

void shellSort(siswa arr[], int is_ascending, int sort_by) {
  int n = len(arr);
  int is_swapped;
  for (int gap = n / 2; gap > 0; gap /= 2) {
    is_swapped = 0;
    for (int i = gap; i < n; i += 1) {
      siswa temp = arr[i];
      int j;
      for (j = i;
           j >= gap && (urut(&arr[j - gap], &temp, sort_by, is_ascending));
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

void insertionSort(siswa arr[], int is_ascending, int sort_by) {
  for (int i = 1; i < len(arr); i++) {
    siswa key = arr[i];
    int j = i - 1;
    for (; j >= 0 && urut(&arr[j], &key, sort_by, is_ascending); j--)
      arr[j + 1] = arr[j];
    arr[j + 1] = key;
  }
}

void selectionSort(siswa arr[], int is_ascending, int sort_by) {
  for (int i = 0; i < len(arr); i++) {
    int temp, min = i;
    for (int j = i + 1; j < len(arr); j++) {
      if (urut(&arr[j], &arr[min], sort_by, is_ascending)) {
        min = j;
      }
    }
    swap(&arr[i], &arr[min]);
  }
}

int urut(siswa *a, siswa *b, int kategori, int is_ascending) {
  int value;
  switch (kategori) {
  case 1:
    value = is_ascending ? a->no > b->no : a->no < b->no;
    break;
  // no
  case 2:
    value = is_ascending ? strcasecmp(a->nama, b->nama) < 0
                         : strcasecmp(a->nama, b->nama) >= 0;
  // nama
  case 3:
    value = is_ascending ? a->nilai > b->nilai : a->nilai < b->nilai;
    break;
    // nilai
  }
  return value;
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

int kategori_urut() {
  int pilihan;
  printf("\nPengurutan berdasarkan:\n");
  printf("1. No.\n");
  printf("2. Nama\n");
  printf("3. Nilai\n");
  printf("Pilihan anda [1/2/3]: ");
  scanf("%d", &pilihan);
  return pilihan;
}
void print_array(siswa *arr) {
  printf("Data siswa:\n");
  for (int i = 0; i < len(arr); i++)
    printf("No: %d, Nama: %s, Nilai: %d\n", arr[i].no, arr[i].nama,
           arr[i].nilai);
  printf("\n");
}

void swap(siswa *a, siswa *b) {
  siswa temp = *a;
  *a = *b;
  *b = temp;
}

void input_array(siswa *array) {
  int jumlah_siswa;
  printf("Berapa siswa yang akan diinput: ");
  scanf("%d", &jumlah_siswa);
  printf("Enter data for %d students:\n", jumlah_siswa);
  for (int i = 0; i < jumlah_siswa; i++) {
    printf("Student %d:\n", i + 1);
    printf("No: ");
    scanf("%d", &array[i].no);
    printf("Name: ");
    scanf("%s", array[i].nama);
    printf("Value: ");
    scanf(" %d", &array[i].nilai);
  }
}

int len(siswa arr[]) {
  int length = 0;
  while (arr[length].no != NULL) {
    length++;
  }
  return length;
}
