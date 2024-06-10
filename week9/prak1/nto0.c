#include <stdio.h>
#include <stdlib.h>

int nto0(int);

int main() {
  int n;
  printf("Input n: ");
  scanf("%d", &n);
  nto0(n);
}

int nto0(int n) {
  printf("%d\n", n);
  if (n == 0)
    exit(0);
  n--;
  nto0(n);
}
