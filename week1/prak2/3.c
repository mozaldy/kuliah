#include <stdio.h>
#include <stdlib.h>
int main() {
  char *pblok;
  pblok = (char *)malloc(500 * sizeof(char));
  if (pblok == NULL)
    puts("Error on malloc");
  else {
    puts("OK, alokasi memory sudah dilakukan");
    puts("------");
    free(pblok);
    pblok = NULL;
    puts("Blok memory telah dibebaskan kembali");
    puts("dan pointernya sdh di - groundkan");
  }
}
