#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
  int data;
  struct dnode *next, *prev;
} dnode;

void alokasi();
void dll_akhir();
void tampil();

dnode *p, *head = NULL;

int main() {
  printf("DLL Insert akhir\n");
  do {
    alokasi();
    dll_akhir();
    printf("Mau lagi (y/t) ? ");
  } while (getchar() == 'y');
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

void dll_akhir() {
  dnode *akhir = head;
  if (head == NULL) {
    head = p;
    return;
  } else {
    while (akhir->next != NULL) {
      akhir = akhir->next;
    }
  }
  akhir->next = p;
}

void tampil() {
  dnode *tampil = head;
  while (tampil != NULL) {
    printf("%d\n", tampil->data);
    tampil = tampil->next;
  }
}
