#include <stdio.h>
#include <stdlib.h>

#define M 10000

typedef struct {
  int *data;
  int front;
  int rear;
  int size;
} Queue;

Queue queue;

void initializeMatrices(int ***Q, int n);
void freeMatrices(int **Q, int n);
void inputGraph(int ***Q, int *n);
void printMatrix(int **mat, int n, const char *name);
void djikstraAlgorithm(int **Q, int *TQ, int *R, int start, int end, int n);
void printPath(int *R, int start, int end);

void initializeQueue(Queue *queue, int size);
void enQueue(Queue *queue, int value);
void deQueue(Queue *queue);
void printQueue(Queue *queue);
int isEmpty(Queue *queue);
int isFull(Queue *queue);
int isInQueue(Queue *queue, int value);

int main() {
  int **Q, *TQ, *R;
  int n;
  int start, end;

  inputGraph(&Q, &n);

  TQ = (int *)malloc(n * sizeof(int));
  R = (int *)malloc(n * sizeof(int));

  printMatrix(Q, n, "Matriks Beban asal (Q)");

  printf("Masukkan Asal (1-%d): ", n);
  scanf("%d", &start);
  printf("Masukkan Tujuan (1-%d): ", n);
  scanf("%d", &end);

  djikstraAlgorithm(Q, TQ, R, start - 1, end - 1, n);

  printf("Rute terpendek dari %d ke %d adalah: ", start, end);
  printPath(R, start - 1, end - 1);
  printf("\n");

  printf("Total beban: %d\n", TQ[end - 1]);

  printf("Matriks TQ\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", TQ[i]);
  }
  printf("\n");

  printf("Matriks R\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", R[i]);
  }
  printf("\n");

  free(TQ);
  free(R);
  freeMatrices(Q, n);

  return 0;
}

void initializeMatrices(int ***Q, int n) {
  *Q = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    (*Q)[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      (*Q)[i][j] = M;
    }
  }
}

void freeMatrices(int **Q, int n) {
  for (int i = 0; i < n; i++) {
    free(Q[i]);
  }
  free(Q);
}

void inputGraph(int ***Q, int *n) {
  printf("Masukkan jumlah node: ");
  scanf("%d", n);

  initializeMatrices(Q, *n);

  printf(
      "Masukkan beban untuk tiap edge (gunakan %d untuk tidak ada koneksi):\n",
      M);
  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < *n; j++) {
      if (i != j) {
        printf("Beban dari node %d ke node %d: ", i + 1, j + 1);
        scanf("%d", &(*Q)[i][j]);
      } else {
        (*Q)[i][j] = M;
      }
    }
  }
}

void printMatrix(int **mat, int n, const char *name) {
  printf("%s:\n", name);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == M) {
        printf("M ");
      } else {
        printf("%d ", mat[i][j]);
      }
    }
    printf("\n");
  }
}

void initializeQueue(Queue *queue, int size) {
  queue->data = (int *)malloc(size * sizeof(int));
  queue->front = -1;
  queue->rear = -1;
  queue->size = size;
}

void enQueue(Queue *queue, int value) {
  if (isFull(queue)) {
    printf("Queue is full\n");
  } else {
    if (isEmpty(queue)) {
      queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->data[queue->rear] = value;
  }
}

void deQueue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
  } else {
    if (queue->front == queue->rear) {
      queue->front = -1;
      queue->rear = -1;
    } else {
      queue->front = (queue->front + 1) % queue->size;
    }
  }
}

void printQueue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
  } else {
    int i = queue->front;
    while (i != queue->rear) {
      printf("%d ", queue->data[i]);
      i = (i + 1) % queue->size;
    }
    printf("%d\n", queue->data[i]);
  }
}

int isEmpty(Queue *queue) { return queue->front == -1; }

int isFull(Queue *queue) {
  return (queue->rear + 1) % queue->size == queue->front;
}

int isInQueue(Queue *queue, int value) {
  if (isEmpty(queue)) {
    return 0;
  } else {
    int i = queue->front;
    while (i != queue->rear) {
      if (queue->data[i] == value) {
        return 1;
      }
      i = (i + 1) % queue->size;
    }
    if (queue->data[i] == value) {
      return 1;
    }
    return 0;
  }
}

void djikstraAlgorithm(int **Q, int *TQ, int *R, int start, int end, int n) {
  int i, j;
  initializeQueue(&queue, n);
  for (i = 0; i < n; i++) {
    TQ[i] = M;
    R[i] = -1;
  }
  TQ[start] = 0;
  enQueue(&queue, start);
  while (!isEmpty(&queue)) {
    int currentNode = queue.data[queue.front];
    deQueue(&queue);
    for (i = 0; i < n; i++) {
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

void printPath(int *R, int start, int end) {
  if (start == end) {
    printf("%d", start + 1);
  } else if (R[end] == -1) {
    printf("Tidak ada rute");
  } else {
    printPath(R, start, R[end]);
    printf(" - %d", end + 1);
  }
}
