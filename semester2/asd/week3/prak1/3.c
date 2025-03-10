#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef struct node {
  int number;
  struct node *next;
} node;

void alokasi();
void display();
void bebas();

void insert_awal();

void hapus_tertentu();

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
  hapus_tertentu();
  display();
  bebas();

  return 0;
}

void alokasi() {
  int number;

  printf("Input angka: ");
  scanf("%d", &number);

  p = (node *)malloc(sizeof(node));

  if (p != NULL) {
    p->number = number;
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

void hapus_tertentu() {
  int key;
  node *hapus = head;
  node *prev_hapus = NULL;

  printf("Angka yang ingin dihapus: ");
  scanf("%d", &key);

  if (hapus != NULL && hapus->number == key) {
    head = hapus->next;
    free(hapus);
    return;
  }

  while (hapus != NULL && hapus->number != key) {
    prev_hapus = hapus;
    hapus = hapus->next;
  }

  if (hapus == NULL)
    return;

  prev_hapus->next = hapus->next;

  free(hapus);
  printf("\nTerhapus\n");
}

void display() {
  node *head_copy;
  printf("\n");
  for (head_copy = head; head_copy != NULL; head_copy = head_copy->next) {
    printf("%i\n", head_copy->number);
  }
}

void bebas() {
  while (head != NULL) {
    node *tmp = head->next;
    free(head);
    head = tmp;
  }
}
