#include "stdio.h"

typedef struct {
  int d, m, y;
} Date;

int sameDay(Date, Date);

typedef struct {
  char name[60];
  double averageScore;
  Date dob; // date of birth
} Student;

struct Class {
  Student stud[30];
  int numStud;
};
int main() {
  Date day1 = {20, 10, 2004};
  Date day2 = {20, 10, 2004};
  if (sameDay(day1, day2))
    printf("It is the same day.\n");
  else
    printf("It is not the same day.\n");
}
int sameDay(Date day1, Date day2) {
  return day1.d == day2.d && day1.m == day2.m && day1.y == day2.y;
}
