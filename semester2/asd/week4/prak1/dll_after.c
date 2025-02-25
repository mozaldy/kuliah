#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
  int data;
  struct dnode *next, *prev;
} dnode;

void alokasi();
void after();
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
  after();
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

void after() {
  int key;
  dnode *after = head;
  alokasi();
  printf("Key ingin dimasukkan setelah angka berapa: ");
  scanf("%d", &key);
  while (after->data != key) {
    if (after->next == NULL) {
      printf("Key tersebut tidak ada dalam linked list!\n");
      exit(0);
    }
    after = after->next;
  }

  p->next = after->next;
  p->prev = after;
  if (after->next != NULL)
    after->next->prev = p;
  after->next = p;
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
