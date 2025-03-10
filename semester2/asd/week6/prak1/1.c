#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define MAX 5

typedef struct {
  int data[MAX];
  int count;
} stack;

void display_menu();

void initialize(stack *);
bool is_full(stack *);
bool is_empty(stack *);
void push(stack *, int);
void pop(stack *);
void pop_all(stack *);

int main(int argc, char *argv[]) {
  stack tumpukan;
  int user_menu, input;
  initialize(&tumpukan);
  do {
    display_menu();
    scanf("%d", &user_menu);
    switch (user_menu) {
    case 1:
      printf("Input angka anda: ");
      scanf("%d", &input);
      push(&tumpukan, input);
      break;
    case 2:
      printf("Data yang anda ambil adalah: ");
      pop(&tumpukan);
      break;
    case 3:
      printf("Isi dari stack saat ini adalah:\n");
      pop_all(&tumpukan);
      break;
    case 4:
      break;
    default:
      printf("Invalid input, try again!\n");
      break;
    }
    printf("\n");
  } while (user_menu != 4);
  return EXIT_SUCCESS;
}

void initialize(stack *s) { s->count = 0; }

bool is_full(stack *s) { return s->count == MAX; }

bool is_empty(stack *s) { return s->count == 0; }

void push(stack *s, int input) {
  if (is_full(s)) {
    printf("Stack sudah penuh!\n");
  } else {
    s->data[s->count] = input;
    s->count++;
  }
}

void pop(stack *s) {
  if (is_empty(s)) {
    printf("Stack sudah kosong!\n");
  } else {
    s->count--;
    printf("%d\n", s->data[s->count]);
  }
}

void pop_all(stack *s) {
  while (s->count != 0)
    pop(s);
}

void display_menu() {
  printf("MENU STACK USING ARRAY:\n");
  printf("1. Mengisi ke Stack (PUSH)\n");
  printf("2. Mengambil dari Stack (POP)\n");
  printf("3. Menampilkan isi Stack (LIFO)\n");
  printf("4. Keluar\n");
  printf("\nPilihan anda: ");
}
