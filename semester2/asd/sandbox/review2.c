#include "stdio.h"
#include "stdlib.h"

typedef struct node {
  int no, nilai;
  char nama[25];
  struct node *next;
} node;

void insert();
void delete();
void search();

void menu();
void alokasi();
void tampil();
void bebas();

node *head = NULL, *p;

int main(int argc, char *argv[]) {
  printf("Review Materi Linked List!\n");
  do {
    menu();
    tampil();
    getchar();
    printf("Ulang lagi (y/t) ? ");
  } while (getchar() == 'y');

  return EXIT_SUCCESS;
}

void menu() {
  int user_menu;
  printf("1. Insert\n");
  printf("2. Delete\n");
  printf("3. Cari\n");
  printf("4. Keluar\n");
  printf("Pilihan anda: ");
  scanf("%d", &user_menu);
  switch (user_menu) {
  case 1:
    alokasi();
    insert();
    break;
  case 2:
    delete ();
    break;
  case 3:
    search();
    break;
  case 4:
    printf("Keluar dari program\n");
    bebas();
    exit(0);
  default:
    break;
  }
}

void alokasi() {

  p = malloc(sizeof(node));
  if (p == NULL) {
    printf("Fatal Error.\n");
    exit(0);
  }

  printf("no\t: ");
  scanf("%d", &p->no);
  printf("nama\t: ");
  scanf("%s", p->nama);
  printf("nilai\t: ");
  scanf("%d", &p->nilai);

  p->next = NULL;
}

void insert() {
  if (head == NULL) {
    head = p;
  } else if (p->no < head->no) {
    p->next = head;
    head = p;
  } else {
    node *after = head;
    while (after != NULL) {
      if (after->next == NULL) {
        after->next = p;
        return;
      }
      if (p->no < after->next->no) {
        p->next = after->next;
        after->next = p;
        return;
      }
      after = after->next;
    }
  }
}

void delete() {
  node *hapus = head, *prev_hapus;
  int input;

  printf("Input angka untuk dihapus: ");
  scanf("%d", &input);

  if (hapus->no == input) {
    head = head->next;
  }
  while (hapus->no != input) {
    if (hapus->next == NULL) {
      printf("Angka %d tidak ada dalam linked list!\n", input);
      return;
    }
    prev_hapus = hapus;
    hapus = hapus->next;
  }

  prev_hapus->next = hapus->next;

  free(hapus);
  hapus = NULL;
}

void search() {
  node *cari = head;
  int input, counter = 0;

  printf("Input angka untuk dicari: ");
  scanf("%d", &input);

  while (cari != NULL) {
    if (cari->no == input) {
      counter++;
    }
    cari = cari->next;
  }

  printf("Ada %d angka %d di dalam linked list.\n", counter, input);
}

void tampil() {
  float avg = 0;
  int data_counter = 0;
  node *head_copy = head;
  printf("\nData linked list:\n");
  printf("No\tNama\tNilai\n");
  while (head_copy != NULL) {
    printf("%d\t%s\t%d\n", head_copy->no, head_copy->nama, head_copy->nilai);
    avg += head_copy->nilai;
    head_copy = head_copy->next;
    data_counter++;
  }

  avg /= data_counter;
  printf("Rata-rata kelas: %g\n", avg);
}
void bebas() {
  while (head != NULL) {
    node *hapus = head;
    head = head->next;
    free(hapus);
  }
}
