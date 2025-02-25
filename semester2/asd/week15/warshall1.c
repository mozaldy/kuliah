#include <stdio.h>

#define M 10000
#define N 5

typedef struct {
  int data[N];
  int top;
} Stack;

void initializeStack(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);

void initializeMatrices(int Q[N][N], int P[N][N], int R[N][N]);
void printMatrix(int mat[N][N], const char *name);
void warshallAlgorithm(int Q[N][N], int P[N][N], int R[N][N]);
void findRoute(int R[N][N], int start, int end);

int main() {
  int Q[N][N], P[N][N], R[N][N];
  int start, end;

  initializeMatrices(Q, P, R);

  printMatrix(Q, "Matriks Beban (Q)");
  printMatrix(P, "Matriks Jalur (P)");
  printMatrix(R, "Matriks Rute (R)");

  warshallAlgorithm(Q, P, R);

  printf("MATRIKS Q-P-R BARU\n");
  printMatrix(Q, "Matriks Beban Baru (Q)");
  printMatrix(P, "Matriks Jalur Baru (P)");
  printMatrix(R, "Matrix Rute Baru (R)");

  printf("Masukkan Asal (1-5): ");
  scanf("%d", &start);
  printf("Masukkan Tujuan (1-5): ");
  scanf("%d", &end);
  findRoute(R, start - 1, end - 1);
  printf("Beban = %d\n", Q[start - 1][end - 1]);

  return 0;
}

void initializeMatrices(int Q[N][N], int P[N][N], int R[N][N]) {
  int i, j;
  int beban[N][N] = {{M, 1, 3, M, M},
                     {M, M, 1, M, 5},
                     {3, M, M, 2, M},
                     {M, M, M, M, 1},
                     {M, M, M, M, M}};
  int jalur[N][N] = {{0, 1, 1, 0, 0},
                     {0, 0, 1, 0, 1},
                     {1, 0, 0, 1, 0},
                     {0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 0}};
  int rute[N][N] = {{M, 1, 1, M, M},
                    {M, M, 1, M, 1},
                    {1, M, M, 1, M},
                    {M, M, M, M, 1},
                    {M, M, M, M, M}};
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      Q[i][j] = beban[i][j];
      P[i][j] = jalur[i][j];
      R[i][j] = rute[i][j];
    }
  }
}

void printMatrix(int mat[N][N], const char *name) {
  printf("%s:\n", name);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (mat[i][j] == M) {
        printf("M ");
      } else {
        printf("%d ", mat[i][j]);
      }
    }
    printf("\n");
  }
}

void warshallAlgorithm(int Q[N][N], int P[N][N], int R[N][N]) {
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (Q[i][k] != M && Q[k][j] != M && Q[i][k] + Q[k][j] < Q[i][j]) {
          Q[i][j] = Q[i][k] + Q[k][j];
          P[i][j] = 1;
          R[i][j] = k + 1;
        }
      }
    }
  }
}

void initializeStack(Stack *stack) { stack->top = -1; }

int isEmpty(Stack *stack) { return stack->top == -1; }
void push(Stack *stack, int value) {
  if (stack->top < N - 1) {
    stack->data[++(stack->top)] = value;
  }
}

int pop(Stack *stack) {
  if (!isEmpty(stack)) {
    return stack->data[(stack->top)--];
  }
  return -1;
}

void findRoute(int R[N][N], int start, int end) {
  Stack stack;
  initializeStack(&stack);

  printf("Rute yang terpendek adalah: %d ", start + 1);
  while (start != end) {
    if (R[start][end] == M) {
      printf("Tidak ada rute dari %d ke %d\n", start + 1, end + 1);
      return;
    }
    push(&stack, end);
    end = R[start][end] - 1;
  }
  while (!isEmpty(&stack)) {
    printf("- %d ", pop(&stack) + 1);
  }
  printf("\n");
}
