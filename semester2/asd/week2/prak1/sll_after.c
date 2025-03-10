#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef char *String;
typedef struct node {
  int number;
  struct node *next;
} node;

void alokasi();
void insert_awal();
void display();
void insert_after();

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
  insert_after();
  display();
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

void insert_after() {
  int key;

  alokasi();

  printf("Disisipkan setelah angka berapa? ");
  scanf("%d", &key);

  node *after;
  for (after = head; after->number != key; after = after->next) {
    if (after->next == NULL) {
      printf("Nilai %d tidak ada di dalam list!\n", key);
      exit(0);
    }
  }
  p->next = after->next;
  after->next = p;
}

void display() {
  node *head_copy;
  for (head_copy = head; head_copy != NULL; head_copy = head_copy->next) {
    printf("%i\n", head_copy->number);
  }
}
