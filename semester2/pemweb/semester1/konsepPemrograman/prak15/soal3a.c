#include <stdio.h>
int tambah(int, int);

int main() {
  int a = 10;
  int b = 20;

  // Memanggil fungsi tambah dengan pass by value
  int c = tambah(a, b);

  // Nilai a dan b tidak berubah
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);

  return 0;
}

int tambah(int x, int y) {
  return x + y;
}