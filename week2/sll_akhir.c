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
void insert_akhir();
void display();

node *head = NULL, *p;
int main() {
  bool input = true;
  while (input) {
    alokasi();
    insert_akhir();
    printf("Input angka lagi (y/t) ? ");
    getchar();
    if (getchar() == 't') {
      input = false;
    }
  }
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

void display() {
  node *head_copy;
  for (head_copy = head; head_copy != NULL; head_copy = head_copy->next) {
    printf("%i\n", head_copy->number);
  }
  head_copy = head;
  while (head_copy != NULL) {
    node *next = head_copy->next;
    free(head_copy);
    head_copy = next;
  }
}
