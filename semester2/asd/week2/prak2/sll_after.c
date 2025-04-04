#include "stdio.h"
#include "stdlib.h"

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
void insert_akhir();
void insert_after();
void tampil();
void bebas();

node *head = NULL, *p;
int main() {
  bool input_loop = true;
  printf("Linked list insert di awal\n");
  while (input_loop) {
    alokasi();
    insert_akhir();
    getchar();
    printf("Ada data lagi (y/t) ? ");
    char input = getchar();
    if (input == 't' || input == 'T')
      input_loop = false;
  }
  tampil();
  insert_after();
  tampil();
  bebas();
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
  printf("Data yang ingin disisipkan\n");
  alokasi();
  printf("Disisipkan setelah angka berapa: ");
  scanf("%d", &key);

  node *after;
  for (after = head; after->no != key; after = after->next) {
    if (after == NULL) {
      printf("Angka %d tidak ada di dalam list!\n", key);
    }
  }

  p->next = after->next;
  after->next = p;
}

void tampil() {
  printf("No.\tNama\tNilai\n");
  for (node *head_copy = head; head_copy != NULL; head_copy = head_copy->next) {
    printf("%d\t%s\t%g\n", head_copy->no, head_copy->nama, head_copy->nilai);
  }
}

void bebas() {
  while (head != NULL) {
    node *tmp = head->next;
    free(head->nama);
    free(head);
    head = tmp;
  }
}
