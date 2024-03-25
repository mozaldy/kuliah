
#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
  int data;
  struct dnode *next, *prev;
} dnode;

void alokasi();
void dll_awal();
void delete_akhir();
void tampil();

dnode *p, *head = NULL, *hapus;

int main() {
  printf("DLL Insert awal\n");
  do {
    alokasi();
    dll_awal();
    printf("Mau lagi (y/t) ? ");
  } while (getchar() == 'y');
  tampil();
  delete_akhir();
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
void delete_akhir() {
  hapus = head;
  while (hapus->next != NULL) {
    hapus = hapus->next;
  }

  if (hapus->prev != NULL)
    hapus->prev->next = NULL;
  else
    head = NULL;

  free(hapus);
  hapus = NULL;
}
