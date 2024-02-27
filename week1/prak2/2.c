#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char s1[] = "This is a sentence";
  char *pblok;
  pblok = (char *)malloc(strlen(s1) + 1);
  /* Remember that stings are terminated by the null
  terminator, "\0', & the strlen returns the length of a
  string not including the terminator
  */
  if (pblok == NULL)
    printf("Error on malloc\n");
  else {
    strcpy(pblok, s1);
    printf("s1: %s\n", s1);
    printf("pblok: %s\n", pblok);
  }
}
