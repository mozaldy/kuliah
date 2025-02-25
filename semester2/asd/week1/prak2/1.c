#include <stdio.h>
typedef struct employee_st {
  char name[40];
  int id;
} employee;
int main() {
  int myint;
  employee john;
  printf("size of int is %lu\n", sizeof(myint));
  // the argument of sizeof is an object
  printf("size of int is %lu\n", sizeof(int));
  // the argument of sizeof is a data type
  printf("size of employee is %lu\n", sizeof(employee));
  // the argument of sizeof is an object
  printf("size of john is %lu\n", sizeof(john));
  // the argument of sizeof is a data type
  printf("size of char is %lu\n", sizeof(char));
  printf("size of short is %lu\n", sizeof(short));
  printf("size of int is %lu\n", sizeof(int));
  printf("size of long is %lu\n", sizeof(long));
  printf("size of float is %lu\n", sizeof(float));
  printf("size of double is %lu\n", sizeof(double));
}
