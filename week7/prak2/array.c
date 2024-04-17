#include "stdio.h"


#define MAX 5


typedef char ItemType;


typedef struct {
  int count, front, rear;
  ItemType data[MAX];
} queue;


void display_menu();
void display_queue(queue *);


void initialize(queue *);
void enqueue(ItemType, queue *);
ItemType dequeue(queue *);
int is_full(queue *);
int is_empty(queue *);


int main(int argc, char *argv[]) {
  queue antrian;
  initialize(&antrian);
  char input;
  do {
    display_menu();
    input = getchar();
    getchar();
    switch (input) {
    case '1':
      printf("Masukkan data anda: ");
      input = getchar();
      getchar();
      enqueue(input, &antrian);
      break;
    case '2':
      printf("Item yang anda ambil adalah %c.\n", dequeue(&antrian));
      break;
    case '3':
      display_queue(&antrian);
      break;
    case '4':
      printf("Keluar dari program.\n");
      break;
    default:
      printf("Pilihan tidak valid.\n");
      break;
    }
  } while (input != '4');
}


void initialize(queue *q) { q->count = q->front = q->rear = 0; }


void enqueue(ItemType data, queue *q) {
  if (is_full(q)) {
    printf("Queue is already full!\n");
  } else {
    q->data[q->rear] = data;
    q->rear++;
    q->count++;
  }
}


ItemType dequeue(queue *q) {
  ItemType temp;
  if (is_empty(q)) {
    printf("Queue is already empty!\n");
    temp = ' ';
  } else {
    temp = q->data[q->front];
    q->front++;
    q->count--;
  }
  return temp;
}
int is_full(queue *q) { return q->count == MAX; }
int is_empty(queue *q) { return q->count == 0; }
void display_menu() {
  printf("\nMenu QUEUE using ARRAY\n");
  printf("1. Mengisi Queue (ENQUEUE)\n");
  printf("2. Mengambil isi Queue (DEQUEUE)\n");
  printf("3. Menampilkan isi Queue -> FIFO\n");
  printf("4. Keluar\n");
  printf("Masukkan pilihan anda: ");
}


void display_queue(queue *q) {
  int front = q->front, rear = q->rear;
  while (front <= rear) {
    printf("%c\n", q->data[front]);
    front++;
  }
}
