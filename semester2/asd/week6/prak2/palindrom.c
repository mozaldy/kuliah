#include "stdbool.h"
#include "stdio.h"

#define MAX 100

typedef char itemType;
typedef struct {
  itemType data[MAX];
  int count;
} stack;

void initialize(stack *);
bool isempty(stack *);
bool isfull(stack *);
void push(stack *, itemType);
itemType pop(stack *s);

void display_menu();

int main(int argc, char *argv[]) {
  stack tumpukan;
  char input[20], menu;
  do {
    printf("Masukkan kata yang ingin dicek: ");
    fgets(input, sizeof(input), stdin);
    printf("Mau coba lagi (y/t) ? ");
    menu = getchar();
    getchar();
  } while (menu == 'y' || menu == 'Y');
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
