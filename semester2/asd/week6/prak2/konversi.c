#include "stdbool.h"
#include "stdio.h"

#define MAX 100

typedef int itemType;
typedef struct {
  itemType data[MAX];
  int count;
} stack;

void initialize(stack *);
bool isempty(stack *);
bool isfull(stack *);
void push(stack *, itemType);
itemType pop(stack *s);

void tobinary(stack *, int);
void tooctal(stack *, int);
void tohex(stack *, int);

void display_menu();

int main(int argc, char *argv[]) {
  stack tumpukan;
  int input, menu;
  printf("Masukkan bilangan decimal: ");
  scanf("%d", &input);
  while (true) {
    display_menu();
    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    initialize(&tumpukan);
    switch (menu) {
    case 1:
      tobinary(&tumpukan, input);
      break;
    case 2:
      tooctal(&tumpukan, input);
      break;
    case 3:
      tohex(&tumpukan, input);
      break;
    case 4:
      printf("Keluar.\n");
      return 0;
      break;
    default:
      printf("Pilihan invalid!\n");
      break;
    }
    while (!isempty(&tumpukan))
      printf("%d", pop(&tumpukan));
    printf("\n");
  }
  return 0;
}

void initialize(stack *s) { s->count = 0; }

bool isempty(stack *s) { return s->count == 0; }

bool isfull(stack *s) { return s->count == MAX; }

void push(stack *s, itemType n) {
  s->data[s->count] = n;
  s->count++;
}

itemType pop(stack *s) {
  s->count--;
  itemType popped = s->data[s->count];
  return popped;
}

void display_menu() {
  printf("\nMENU KONVERSI:\n");
  printf("1. Binary\n");
  printf("2. Octal\n");
  printf("3. Hexadecimal\n");
  printf("4. Keluar\n\n");
}

void tobinary(stack *s, int n) {
  while (n > 0) {
    push(s, n % 2);
    n /= 2;
  }
}

void tooctal(stack *s, int n) {
  while (n > 0) {
    push(s, n % 8);
    n /= 8;
  }
}

void tohex(stack *s, int n) {
  while (n > 0) {
    push(s, n % 16);
    n /= 16;
  }
}
