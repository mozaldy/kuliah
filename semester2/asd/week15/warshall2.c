#include <stdio.h>
#include <stdlib.h>

#define M 10000

typedef struct {
  int data;
  int *route;
} Node;

typedef struct {
  Node *nodes;
  int size;
} Graph;

typedef struct StackNode {
  int data;
  struct StackNode *next;
} StackNode;

typedef struct {
  StackNode *top;
} Stack;

void initializeStack(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);

void initializeGraph(Graph *graph, int size);
void input(Graph *graph);
void printGraph(Graph *graph);
void warshallAlgorithm(Graph *graph);
void findRoute(Graph *graph, int start, int end);

int main() {
  Graph graph;
  input(&graph);

  printGraph(&graph);

  warshallAlgorithm(&graph);

  printf("MATRIKS Q-P-R BARU\n");
  printGraph(&graph);

  int start, end;
  printf("Masukkan Asal (1-%d): ", graph.size);
  scanf("%d", &start);
  printf("Masukkan Tujuan (1-%d): ", graph.size);
  scanf("%d", &end);
  findRoute(&graph, start - 1, end - 1);

  return 0;
}

void initializeStack(Stack *stack) { stack->top = NULL; }

int isEmpty(Stack *stack) { return stack->top == NULL; }

void push(Stack *stack, int value) {
  StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = value;
  newNode->next = stack->top;
  stack->top = newNode;
}

int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
  }
  StackNode *temp = stack->top;
  int value = temp->data;
  stack->top = temp->next;
  free(temp);
  return value;
}

void initializeGraph(Graph *graph, int size) {
  graph->size = size;
  graph->nodes = (Node *)malloc(size * sizeof(Node));
  if (graph->nodes == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < size; i++) {
    graph->nodes[i].data = M;
    graph->nodes[i].route = (int *)malloc(size * sizeof(int));
    if (graph->nodes[i].route == NULL) {
      printf("Memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
    for (int j = 0; j < size; j++) {
      graph->nodes[i].route[j] = M;
    }
  }
}

void input(Graph *graph) {
  int size;
  printf("Masukkan jumlah node: ");
  scanf("%d", &size);
  initializeGraph(graph, size);

  printf("Masukkan beban antar node (M untuk tidak ada jalur):\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      char input[10];
      scanf("%s", input);
      if (input[0] == 'M') {
        graph->nodes[i].route[j] = M;
      } else {
        graph->nodes[i].route[j] = atoi(input);
      }
    }
  }
}

void printGraph(Graph *graph) {
  printf("Matriks Beban (Q):\n");
  for (int i = 0; i < graph->size; i++) {
    for (int j = 0; j < graph->size; j++) {
      if (graph->nodes[i].route[j] == M) {
        printf("M ");
      } else {
        printf("%d ", graph->nodes[i].route[j]);
      }
    }
    printf("\n");
  }
}

void warshallAlgorithm(Graph *graph) {
  for (int k = 0; k < graph->size; k++) {
    for (int i = 0; i < graph->size; i++) {
      for (int j = 0; j < graph->size; j++) {
        if (graph->nodes[i].route[k] != M && graph->nodes[k].route[j] != M &&
            graph->nodes[i].route[k] + graph->nodes[k].route[j] <
                graph->nodes[i].route[j]) {
          graph->nodes[i].route[j] =
              graph->nodes[i].route[k] + graph->nodes[k].route[j];
        }
      }
    }
  }
}

void findRoute(Graph *graph, int start, int end) {
  Stack stack;
  initializeStack(&stack);

  printf("Rute yang terpendek adalah: %d ", start + 1);
  while (start != end) {
    if (graph->nodes[start].route[end] == M) {
      printf("Tidak ada rute dari %d ke %d\n", start + 1, end + 1);
      return;
    }
    push(&stack, end);
    end = graph->nodes[start].route[end];
  }
  while (!isEmpty(&stack)) {
    printf("- %d ", pop(&stack) + 1);
  }
  printf("\n");
}
