#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef char *String;

typedef struct siswa {
  int no;
  float nilai;
  String nama;
  struct siswa *next;
} node;

void alokasi();
void display();
void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();

node *head = NULL, *p;

int main(int argc, char *argv[]) {
  bool input_loop = true;
  while (input_loop) {
    display();
    printf("Menu insert\n");
    printf("1. Awal\n");
    printf("2. Akhir\n");
    printf("3. After\n");
    printf("4. Before\n");
    printf("5. Keluar\n");
    printf("Masukkan pilihan anda: ");
    char input = getchar();
    if (input == '5') {
      printf("bye-bye\n");
      exit(0);
    }
    alokasi();
    printf("input: %c", input);
    switch (input) {
    case '1':
      insert_awal();
      break;
    case '2':
      insert_akhir();
      break;
    case '3':
      insert_after();
      break;
    case '4':
      insert_before();
      break;
    case '5':
    default:
      printf("Input tidak valid!\n");
    }
    getchar();
  }

  display();
}

void alokasi() {
  int no;
  float nilai;
  String nama = malloc(255);
  printf("No\t: ");
  scanf("%d", &no);
  printf("Nama\t: ");
  scanf("%s", nama);
  printf("Nilai\t: ");
  scanf("%f", &nilai);

  p = (node *)malloc(sizeof(node));

  if (p != NULL) {
    p->no = no;
    p->nama = nama;
    p->nilai = nilai;
    p->next = NULL;
  } else {
    exit(1);
  }
}

void display() {
  printf("\nNo.\tNama\tNilai\n");
  for (node *head_copy = head; head_copy != NULL; head_copy = head_copy->next) {
    printf("%d\t%s\t%g\n", head_copy->no, head_copy->nama, head_copy->nilai);
  }
  printf("\n");
}

void insert_awal() {

  if (head != NULL) {
    p->next = head;
  }
  head = p;
}

void insert_akhir() {
  if (head == NULL) {
    head = p;
  } else {
    for (node *ptr = head; ptr != NULL; ptr = ptr->next) {
      if (ptr->next == NULL) {
        ptr->next = p;
        break;
      }
    }
  }
}

void insert_after() {
  int key;

  printf("Disisipkan setelah angka berapa? ");
  scanf("%d", &key);

  node *after;
  for (after = head; after->no != key; after = after->next) {
    if (after->next == NULL) {
      printf("Nilai %d tidak ada di dalam list!\n", key);
      exit(0);
    }
  }
  p->next = after->next;
  after->next = p;
}

void insert_before() {
  int key;

  printf("Disisipkan sebelum angka berapa? ");
  scanf("%d", &key);

  if (head->no == key) {
    p->next = head;
    head = p;
    return;
  }

  node *before, *prev_before;
  for (before = head; before != NULL && before->no != key;
       before = before->next) {
    prev_before = before;
  }

  if (before == NULL) {
    printf("Nilai %d tidak ada di dalam list!\n", key);
    free(p);
    return;
  }

  p->next = before;
  prev_before->next = p;
}
