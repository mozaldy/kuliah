#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int NO;
  char Nama[50];
  int Nilai;
} mhs;

mhs *global_array;
int global_jumlah_data;

void generate_data(mhs *arr, int jumlah_data);
void print_data(mhs *arr, int jumlah_data, bool sorted, bool by_no);
void swap(mhs *a, mhs *b);

void sequential_search(int dicari_no, char *dicari_nama, bool by_no);
void binary_search(int dicari_no, char *dicari_nama, bool by_no);

void quick_sort(mhs *arr, int low, int high, bool by_no);
int partition(mhs *arr, int low, int high, bool by_no);

void menu();

int main() {
  int jumlah_data;
  printf("Jumlah data: ");
  scanf("%d", &jumlah_data);
  mhs array[jumlah_data];
  global_array = array;
  global_jumlah_data = jumlah_data;
  generate_data(array, jumlah_data);

  menu();

  return 0;
}

void generate_data(mhs *arr, int jumlah_data) {
  for (int i = 0; i < jumlah_data; i++) {
    arr[i].NO = rand() % 100;
    snprintf(arr[i].Nama, 50, "Nama%d", i + 1);
    arr[i].Nilai = rand() % 100;
  }
}

void print_data(mhs *arr, int jumlah_data, bool sorted, bool by_no) {
  if (sorted) {
    quick_sort(arr, 0, jumlah_data - 1, by_no);
  }
  printf("NO\tNama\t\tNilai\n");
  for (int i = 0; i < jumlah_data; i++) {
    printf("%d\t%s\t\t%d\n", arr[i].NO, arr[i].Nama, arr[i].Nilai);
  }
}

void sequential_search(int dicari_no, char *dicari_nama, bool by_no) {
  bool found = false;
  for (int i = 0; i < global_jumlah_data; i++) {
    if ((by_no && global_array[i].NO == dicari_no) ||
        (!by_no && strcmp(global_array[i].Nama, dicari_nama) == 0)) {
      printf("Ditemukan: NO=%d, Nama=%s, Nilai=%d\n", global_array[i].NO,
             global_array[i].Nama, global_array[i].Nilai);
      found = true;
    }
  }
  if (!found) {
    if (by_no) {
      printf("Data dengan NO %d tidak ditemukan!\n", dicari_no);
    } else {
      printf("Data dengan Nama %s tidak ditemukan!\n", dicari_nama);
    }
  }
}

void binary_search(int dicari_no, char *dicari_nama, bool by_no) {
  quick_sort(global_array, 0, global_jumlah_data - 1, by_no);
  int low = 0, high = global_jumlah_data - 1;
  bool found = false;

  while (low <= high) {
    int mid = (low + high) / 2;
    if ((by_no && global_array[mid].NO == dicari_no) ||
        (!by_no && strcmp(global_array[mid].Nama, dicari_nama) == 0)) {
      printf("Ditemukan: NO=%d, Nama=%s, Nilai=%d\n", global_array[mid].NO,
             global_array[mid].Nama, global_array[mid].Nilai);
      found = true;
      break;
    } else if ((by_no && global_array[mid].NO < dicari_no) ||
               (!by_no && strcmp(global_array[mid].Nama, dicari_nama) < 0)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (!found) {
    if (by_no) {
      printf("Data dengan NO %d tidak ditemukan!\n", dicari_no);
    } else {
      printf("Data dengan Nama %s tidak ditemukan!\n", dicari_nama);
    }
  }
}

void quick_sort(mhs *arr, int low, int high, bool by_no) {
  if (low < high) {
    int pi = partition(arr, low, high, by_no);
    quick_sort(arr, low, pi, by_no);
    quick_sort(arr, pi + 1, high, by_no);
  }
}

int partition(mhs *arr, int low, int high, bool by_no) {
  if (by_no) {
    int pivot = arr[low].NO;
    int i = low - 1;
    int j = high + 1;

    while (true) {
      do {
        i++;
      } while (arr[i].NO < pivot);
      do {
        j--;
      } while (arr[j].NO > pivot);
      if (i >= j)
        return j;
      swap(&arr[i], &arr[j]);
    }
  } else {
    char pivot[50];
    strcpy(pivot, arr[low].Nama);
    int i = low - 1;
    int j = high + 1;

    while (true) {
      do {
        i++;
      } while (strcmp(arr[i].Nama, pivot) < 0);
      do {
        j--;
      } while (strcmp(arr[j].Nama, pivot) > 0);
      if (i >= j)
        return j;
      swap(&arr[i], &arr[j]);
    }
  }
}

void swap(mhs *a, mhs *b) {
  mhs temp = *a;
  *a = *b;
  *b = temp;
}

void menu() {
  int pilihan, sub_pilihan;
  do {
    printf("\nMENU METODE SEARCHING\n");
    printf("1. Tampilkan Data\n");
    printf("2. Sequential Search\n");
    printf("3. Binary Search\n");
    printf("4. Keluar\n");
    printf("Pilihan anda [1/2/3/4]: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
    case 1:
      printf("\nBENTUK DATA\n");
      printf("1. Tidak Terurut\n");
      printf("2. Terurut Berdasarkan No\n");
      printf("Pilihan anda [1/2]: ");
      scanf("%d", &sub_pilihan);
      print_data(global_array, global_jumlah_data, sub_pilihan == 2, true);
      break;
    case 2:
      printf("\nPENCARIAN BERDASARKAN\n");
      printf("1. No\n");
      printf("2. Nama\n");
      printf("Pilihan anda [1/2]: ");
      scanf("%d", &sub_pilihan);
      if (sub_pilihan == 1) {
        int dicari;
        printf("Masukkan no mhs yang akan dicari: ");
        scanf("%d", &dicari);
        sequential_search(dicari, NULL, true);
      } else if (sub_pilihan == 2) {
        char dicari[50];
        printf("Masukkan nama mhs yang akan dicari: ");
        scanf("%s", dicari);
        sequential_search(0, dicari, false);
      }
      break;
    case 3:
      printf("\nPENCARIAN BERDASARKAN\n");
      printf("1. No\n");
      printf("2. Nama\n");
      printf("Pilihan anda [1/2]: ");
      scanf("%d", &sub_pilihan);
      if (sub_pilihan == 1) {
        int dicari;
        printf("Masukkan no mhs yang akan dicari: ");
        scanf("%d", &dicari);
        binary_search(dicari, NULL, true);
      } else if (sub_pilihan == 2) {
        char dicari[50];
        printf("Masukkan nama mhs yang akan dicari: ");
        scanf("%s", dicari);
        binary_search(0, dicari, false);
      }
      break;
    case 4:
      return;
    }
  } while (true);
}
