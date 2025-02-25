#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct employee_st {
  char name[40];
  int id;
} Employee;
int main() {
  Employee *workers, *wpt;
  int num, i;
  printf("How many employees do you want ? ");
  scanf("%d", &num);
  workers = (Employee *)malloc(num * sizeof(Employee));
  if (workers == NULL) {
    printf("Unable to allocated space for employees\n");

    exit(0);
  }
  wpt = workers;
  for (i = 1; i <= num; i++) {
    getchar();
    printf("Employee's name : ");
    fgets(wpt->name, sizeof(wpt->name), stdin);
    printf("Employee's id : ");
    scanf("%d", &wpt->id);
    wpt++;
  }
  puts("");
  wpt = workers;
  for (i = 1; i <= num; i++) {
    printf("Employee %d is %s\n", wpt->id, wpt->name);
    wpt++;
  }
  free(workers);
  workers = NULL;
}
