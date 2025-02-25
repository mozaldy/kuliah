#include <stdio.h>
void tukar(int *, int *);

int main() {
  int a = 10;
  int b = 20;

  // Memanggil fungsi tukar dengan pass by reference
  tukar(&a, &b);

  // Nilai a dan b telah berubah
  printf("a = %d\n", a);
  printf("b = %d\n", b);

  return 0;
}

void tukar(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}