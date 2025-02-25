#include <stdio.h>

#define M 10000
#define N 5

typedef struct {
  int data[N];
  int front;
  int rear;
} Queue;

Queue queue;

void initializeMatrices(int Q[N][N]);
void printMatrix(int mat[N][N], const char *name);
void djikstraAlgorithm(int Q[N][N], int TQ[N], int R[N], int start, int end);
void printPath(int R[N], int start, int end);

void initializeQueue(Queue *Queue);
void enQueue(Queue *Queue, int value);
void deQueue(Queue *Queue);
void printQueue(Queue *Queue);
int isEmpty(Queue *Queue);
int isFull(Queue *Queue);
int isInQueue(Queue *Queue, int value);

int main() {
  int Q[N][N], TQ[N], R[N];
  int start, end;

  initializeMatrices(Q);
  printMatrix(Q, "Matriks Beban asal (Q)");

  printf("Masukkan Asal (1-5): ");
  scanf("%d", &start);
  printf("Masukkan Tujuan (1-5): ");
  scanf("%d", &end);

  djikstraAlgorithm(Q, TQ, R, start - 1, end - 1);

  printf("Rute terpendek dari %d ke %d adalah: ", start, end);
  printPath(R, start - 1, end - 1);
  printf("\n");

  printf("Total beban: %d\n", TQ[end - 1]);

  printf("Matriks TQ\n");
  for (int i = 0; i < N; i++) {
    printf("%d ", TQ[i]);
  }
  printf("\n");

  printf("Matriks R\n");
  for (int i = 0; i < N; i++) {
    printf("%d ", R[i]);
  }
  printf("\n");

  return 0;
}

void initializeMatrices(int Q[N][N]) {
  int i, j;
  int beban[N][N] = {{M, 1, 3, M, M},
                     {M, M, 1, M, 5},
                     {3, M, M, 2, M},
                     {M, M, M, M, 1},
                     {M, M, M, M, M}};
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      Q[i][j] = beban[i][j];
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

void initializeQueue(Queue *Queue) {
  Queue->front = -1;
  Queue->rear = -1;
}

void enQueue(Queue *Queue, int value) {
  if (isFull(Queue)) {
    printf("Queue is full\n");
  } else {
    if (isEmpty(Queue)) {
      Queue->front = 0;
    }
    Queue->rear = (Queue->rear + 1) % N;
    Queue->data[Queue->rear] = value;
  }
}

void deQueue(Queue *Queue) {
  if (isEmpty(Queue)) {
    printf("Queue is empty\n");
  } else {
    if (Queue->front == Queue->rear) {
      Queue->front = -1;
      Queue->rear = -1;
    } else {
      Queue->front = (Queue->front + 1) % N;
    }
  }
}

void printQueue(Queue *Queue) {
  if (isEmpty(Queue)) {
    printf("Queue is empty\n");
  } else {
    int i = Queue->front;
    while (i != Queue->rear) {
      printf("%d ", Queue->data[i]);
      i = (i + 1) % N;
    }
    printf("%d\n", Queue->data[i]);
  }
}

int isEmpty(Queue *Queue) { return Queue->front == -1; }

int isFull(Queue *Queue) { return (Queue->rear + 1) % N == Queue->front; }

int isInQueue(Queue *Queue, int value) {
  if (isEmpty(Queue)) {
    return 0;
  } else {
    int i = Queue->front;
    while (i != Queue->rear) {
      if (Queue->data[i] == value) {
        return 1;
      }
      i = (i + 1) % N;
    }
    if (Queue->data[i] == value) {
      return 1;
    }
    return 0;
  }
}

void djikstraAlgorithm(int Q[N][N], int TQ[N], int R[N], int start, int end) {
  int i, j;
  initializeQueue(&queue);
  for (i = 0; i < N; i++) {
    TQ[i] = M;
    R[i] = -1;
  }
  TQ[start] = 0;
  enQueue(&queue, start);
  while (!isEmpty(&queue)) {
    int currentNode = queue.data[queue.front];
    deQueue(&queue);
    for (i = 0; i < N; i++) {
      if (Q[currentNode][i] != M) {
        if (TQ[currentNode] + Q[currentNode][i] < TQ[i]) {
          TQ[i] = TQ[currentNode] + Q[currentNode][i];
          R[i] = currentNode;
          if (i != start && i != end && !isInQueue(&queue, i)) {
            enQueue(&queue, i);
          }
        }
      }
    }
  }
}

void printPath(int R[N], int start, int end) {
  if (start == end) {
    printf("%d", start + 1);
  } else if (R[end] == -1) {
    printf("Tidak ada rute");
  } else {
    printPath(R, start, R[end]);
    printf(" - %d", end + 1);
  }
}
