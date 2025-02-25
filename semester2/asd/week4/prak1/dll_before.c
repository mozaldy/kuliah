#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
  int data;
  struct dnode *next, *prev;
} dnode;

void alokasi();
void before();
void tampil();
void dll_awal();

dnode *p, *head = NULL;

int main() {
  printf("DLL insert after\n");
  do {
    alokasi();
    dll_awal();
    printf("Mau lagi (y/t) ? ");
  } while (getchar() == 'y');
  tampil();
  before();
  tampil();
}

void alokasi() {
  p = malloc(sizeof(dnode));
  if (p == NULL) {
    printf("Memory tidak dapat dialokasikan!\n");
    exit(1);
  } else {
    p->next = NULL;
    p->prev = NULL;
    printf("Data yang mau disimpan? ");
    scanf("%d", &p->data);
    getchar();
  }
}

void before() {
  int key;
  dnode *before = head;
  alokasi();
  printf("Key ingin dimasukkan sebelum angka berapa: ");
  scanf("%d", &key);
  if (before->data == key) {
    p->next = head;
    head = p;
    return;
  } else {
    while (before->data != key) {
      if (before->next == NULL) {
        printf("Key tersebut tidak ada dalam linked list!\n");
        exit(0);
      }
      before = before->next;
    }
  }

  p->next = before;
  p->prev = before->prev;
  if (before->prev != NULL)
    before->prev->next = p;
  before->prev = p;
}

void dll_awal() {
  if (head != NULL) {
    p->next = head;
    head->prev = p;
  }
  head = p;
}

void tampil() {
  dnode *tampil = head;
  while (tampil != NULL) {
    printf("%d\n", tampil->data);
    tampil = tampil->next;
  }
}
