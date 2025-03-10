#include "stdio.h"
#include "stdlib.h"

#define MAX 5

typedef int ItemType;

typedef struct
{
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
int find_min_max(queue *);
int find_data(queue *, int);

int main(int argc, char *argv[])
{
  queue antrian;
  initialize(&antrian);
  char input;
  do
  {
    display_menu();
    input = getchar();
    getchar();
    switch (input)
    {
    case '1':
      printf("Masukkan data anda: ");
      input = getchar();
      getchar();
      enqueue(input - '0', &antrian);
      break;
    case '2':
      printf("Item %d dihapus.\n", dequeue(&antrian));
      break;
    case '3':
      find_min_max(&antrian);
      break;
    case '4':
      printf("Masukkan data anda: ");
      input = getchar();
      getchar();
      if (find_data(&antrian, input - '0'))
        printf("Data %c ditemukan.\n", input);
      else
        printf("Data %c tidak ditemukan.\n", input);
      break;
    case '5':
      display_queue(&antrian);
      break;
    case '6':
      printf("Keluar dari program.\n");
      break;
    default:
      printf("Pilihan tidak valid.\n");
      break;
    }
  } while (input != '6');
}

void initialize(queue *q) { q->count = q->front = q->rear = 0; }

void enqueue(ItemType data, queue *q)
{
  if (is_full(q))
  {
    printf("Queue is already full!\n");
  }
  else
  {
    q->data[q->rear] = data;
    q->rear++;
    q->count++;
  }
}

ItemType dequeue(queue *q)
{
  ItemType temp;
  if (is_empty(q))
  {
    printf("Queue is already empty!\n");
    temp = ' ';
  }
  else
  {
    temp = q->data[q->front];
    q->front++;
    q->count--;
  }
  return temp;
}
int is_full(queue *q) { return q->count == MAX; }
int is_empty(queue *q) { return q->count == 0; }
void display_menu()
{
  printf("\nMenu QUEUE using ARRAY\n");
  printf("1. Tambah Data\n");
  printf("2. Hapus Data\n");
  printf("3. Tampilkan data Min & Max\n");
  printf("4. Cari data\n");
  printf("5. Cetak isi Queue \n");
  printf("6. Keluar\n");
  printf("Masukkan pilihan anda: ");
}

void display_queue(queue *q)
{
  int front = q->front, rear = q->rear;
  while (front < rear)
  {
    printf("%d\n", q->data[front]);
    front++;
  }
}

int find_min_max(queue *q)
{
  int start = q->front, rear = q->rear, count = q->count, min = 999999, max = 0;
  for (int i = start; i < rear; i++)
  {
    int n = q->data[i];
    if (n < min)
      min = n;
    if (n > max)
      max = n;
  }
  printf("Min: %d\nMax: %d", min, max);
}
int find_data(queue *q, int n)
{
  int start = q->front, end = q->rear, count = q->count;
  for (int i = start; i < end; i++)
  {
    int m = q->data[i];

    if (n == m)
      return 1;
  }
  return 0;
}