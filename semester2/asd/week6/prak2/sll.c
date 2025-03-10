#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int itemType;

typedef struct node {
  itemType data;
  struct node *next;
} Node;

typedef struct {
  Node *top;
  int count;
} stack;

void initialize(stack *stack);
int is_empty(stack *stack);
int is_full(stack *stack);
void push(itemType x, stack *stack);
itemType pop(stack *stack);
void display(stack *stack);

int main() {
  stack tumpukan;
  initialize(&tumpukan);
  int pilihan;
  itemType x;

  while (1) {
    printf("Menu stack\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Tampilkan\n");
    printf("4. Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
    case 1:
      printf("Masukkan data yang akan disimpan: ");
      scanf("%d", &x);
      push(x, &tumpukan);
      break;
    case 2:
      if (!is_empty(&tumpukan)) {
        printf("Data yang diambil: %d\n", pop(&tumpukan));
      } else {
        printf("Stack kosong\n");
      }
      break;
    case 3:
      printf("Isi stack:\n");
      display(&tumpukan);
      break;
    case 4:
      exit(0);
    default:
      printf("Pilihan tidak valid\n");
    }
  }
  return 0;
}

void initialize(stack *stack) {
  stack->top = NULL;
  stack->count = 0;
}

int is_empty(stack *stack) { return stack->top == NULL; }

int is_full(stack *stack) { return stack->count == MAX; }

void push(itemType x, stack *stack) {
  if (is_full(stack)) {
    printf("Stack sudah penuh\n");
    return;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Alokasi memori gagal\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = x;
  newNode->next = stack->top;
  stack->top = newNode;
  stack->count++;
}

itemType pop(stack *stack) {
  if (is_empty(stack)) {
    printf("Stack kosong\n");
    exit(1);
  }
  Node *temp = stack->top;
  itemType poppedData = temp->data;
  stack->top = temp->next;
  free(temp);
  stack->count--;
  return poppedData;
}

void display(stack *stack) {
  if (is_empty(stack)) {
    printf("Stack kosong\n");
    return;
  }
  Node *current = stack->top;
  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->next;
  }
}
