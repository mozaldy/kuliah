#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300

typedef char itemtype;
typedef struct {
  itemtype item[MAX];
  int count;
} stack;

void initialize(stack *s);
int is_empty(stack *s);
int is_full(stack *s);
void push(itemtype x, stack *s);
itemtype pop(stack *s);
int palindrom(char *str);

int main() {
  itemtype str[MAX];

  printf("masukkan kalimat palindrom = ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';

  if (palindrom(str))
    printf("kalimat tersebut adalah palindrom");
  else
    printf("kalimat bukan palindrom");
  return 0;
}

void initialize(stack *s) { s->count = 0; }

int is_empty(stack *s) { return s->count == 0; }

int is_full(stack *s) { return s->count == MAX; }

void push(itemtype x, stack *s) {
  if (is_full(s)) {
    printf("stack sudah penuh");
  } else {
    s->item[s->count++] = x;
  }
}

itemtype pop(stack *s) {
  itemtype x;
  if (is_empty(s)) {
    printf("stack kosong");
    return ' ';
  } else {
    x = s->item[--s->count];
    return x;
  }
}

int palindrom(char *str) {
  int length = strlen(str);
  stack s;
  initialize(&s);

  for (int i = 0; i < length / 2; i++) {
    push(str[i], &s);
  }

  for (int i = length / 2 + (length % 2); i < length; i++) {
    if (str[i] != pop(&s)) {
      return 0;
    }
  }
  return 1;
}
