#include "stdio.h"

typedef struct {
  int d, m, y;
} Date;

typedef struct {
  char name[60];
  double averageScore;
  Date dob; // date of birth
} Student;

int isYounger(Student stud1, Student stud2);

int main() {
  Student stud1 = {"rizaldy", 10, {20, 9, 2004}};
  Student stud2 = {"zaidan", 10, {20, 10, 2004}};
  if (isYounger(stud1, stud2))
    printf("Student %s is younger than %s\n", stud1.name, stud2.name);
  else
    printf("Student %s is not younger than %s\n", stud1.name, stud2.name);
}
int isYounger(Student stud1, Student stud2) {
  if (stud1.dob.y > stud2.dob.y) {
    return 1;
  }
  if (stud1.dob.m > stud2.dob.m) {
    return 1;
  }
  if (stud1.dob.d > stud2.dob.d) {
    return 1;
  }
  return 0;
}
