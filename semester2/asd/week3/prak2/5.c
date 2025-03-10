#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef char *String;
typedef struct node {
  int no;
  String nama;
  float nilai;
  struct node *next;
} node;

void alokasi();
void display();
void bebas();

void insert_awal();

void hapus_after();

node *head = NULL, *p;

int main(int argc, char *argv[]) {
  bool input = true;
  while (input) {
    alokasi();
    insert_awal();
    printf("Input angka lagi (y/t) ? ");
    getchar();
    if (getchar() == 't') {
      input = false;
    }
  }

  display();
  hapus_after();
  display();
  bebas();

  return 0;
}

void alokasi() {
  int no;
  float nilai;
  String nama;

  nama = malloc(sizeof(char) * 20);

  printf("Input no: ");
  scanf("%d", &no);
  printf("Input nilai: ");
  scanf("%f", &nilai);
  printf("Input nama: ");
  scanf("%s", nama);

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

void insert_awal() {
  if (head != NULL) {
    p->next = head;
  }
  head = p;
}

void hapus_after() {
  int key;
  node *hapus = head;
  node *prev_hapus = NULL;

  printf("Angka yang ingin dihapus: ");
  scanf("%d", &key);

  if (hapus != NULL && hapus->no == key) {
    head = hapus->next;
    free(hapus);
    return;
  }
  while (hapus != NULL && hapus->no != key) {
    prev_hapus = hapus;
    hapus = hapus->next;
  }

  hapus = hapus->next;
  prev_hapus = prev_hapus->next;

  if (hapus == NULL)
    return;

  prev_hapus->next = hapus->next;

  free(hapus);
}

void display() {
  node *head_copy;
  printf("No\tNama\tNilai\n");
  for (head_copy = head; head_copy != NULL; head_copy = head_copy->next) {
    printf("%i\t%s\t%g\n", head_copy->no, head_copy->nama, head_copy->nilai);
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
