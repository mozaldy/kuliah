
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define MAX 5

typedef struct {
  char data[MAX];
  int count;
} stack;

void display_menu();

void initialize(stack *);
bool is_full(stack *);
bool is_empty(stack *);
void push(stack *, char);
void pop(stack *);
void pop_all(stack *);

void konversi(char, stack *);
int cari_derajat(char);

int main(int argc, char *argv[]) {
  stack tumpukan;
  char infix[255];
  initialize(&tumpukan);
  char user_input;
  do {
    printf("Masukkan ekspresi dalam notasi infix: ");
    fgets(infix, sizeof(infix), stdin);
    printf("%s\n", infix);
    printf("Ungkapan postfixnya: ");
    for (int i = 0; infix[i] != '\0'; i++)
      konversi(infix[i], &tumpukan);
    printf("\n");
    printf("Do you want to continue (y/n)? ");
    scanf(" %c", &user_input);
    getchar();
  } while (user_input == 'y' || user_input == 'Y');
  return EXIT_SUCCESS;
}

void initialize(stack *s) { s->count = 0; }

bool is_full(stack *s) { return s->count == MAX; }

bool is_empty(stack *s) { return s->count == 0; }

void push(stack *s, char input) {
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
    if (s->data[s->count] != '(')
      printf("%c ", s->data[s->count]);
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

void konversi(char r, stack *s) {
   int char_derajat = cari_derajat(r);
    if ((r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z') || (r >= '0' && r <= '9')) {
        printf("%c ", r);
    } else if (r == '(') {
        push(s, r); 
    } else if (r == ')') {
        while (!is_empty(s) && s->data[s->count - 1] != '(') {
            pop(s);
        }
        if (!is_empty(s)) {
            pop(s);
        }
    } else {
        while (!is_empty(s) && cari_derajat(s->data[s->count - 1]) >= cari_derajat(r)) {
            pop(s);
        }
        push(s, r);
    }
}
int cari_derajat(char r) {
  if (r == '(')
    return 0;
  else if (r == '+' || r == '-')
    return 1;
  else if (r == '*' || r == '/')
    return 2;
  else if (r == '^')
    return 3;

  return -1;
}
