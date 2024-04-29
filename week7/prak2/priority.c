#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef char ItemType;

typedef struct node {
    ItemType data;
    int priority;
    struct node *next;
} node;

typedef struct {
    int count;
    node *head;
} queue;

void display_menu();
void display_queue(queue *);

void initialize(queue *);
void enqueue(ItemType, int, queue *);
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
        getchar(); // Consume newline
        switch (input) {
            case '1':
                printf("Masukkan data anda: ");
                input = getchar();
                getchar(); // Consume newline
                printf("Nilai prioritasnya: ");
                int priority = getchar() - '0';
                getchar(); // Consume newline
                enqueue(input, priority, &antrian);
                break;
            case '2':
                printf("Item yang anda ambil adalah %c.\n", dequeue(&antrian));
                break;
            case '3':
                display_queue(&antrian);
                break;
            case '4':
                printf("Keluar dari program.\n");
                exit(0);
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (1);
    return 0;
}

void initialize(queue *q) {
    q->count = 0;
    q->head = NULL;
}

void enqueue(ItemType data, int priority, queue *q) {
    if (is_full(q)) {
        printf("Queue is already full!\n");
    } else {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL) {
            printf("Memory allocation failure, exiting the program.\n");
            exit(EXIT_FAILURE);
        }
        new_node->data = data;
        new_node->priority = priority;
        new_node->next = NULL;

        if (is_empty(q) || priority < q->head->priority) {
            new_node->next = q->head;
            q->head = new_node;
        } else {
            node *current = q->head;
            while (current->next != NULL && current->next->priority <= priority) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
        q->count++;
    }
}

ItemType dequeue(queue *q) {
    ItemType temp = ' ';
    if (is_empty(q)) {
        printf("Queue is already empty!\n");
    } else {
        node *temp_node = q->head;
        temp = temp_node->data;
        q->head = temp_node->next;
        free(temp_node);
        q->count--;
    }
    return temp;
}

int is_full(queue *q) {
    return q->count == MAX;
}

int is_empty(queue *q) {
    return q->count == 0;
}

void display_menu() {
    printf("\nMenu QUEUE using ARRAY\n");
    printf("1. Mengisi Queue (ENQUEUE)\n");
    printf("2. Mengambil isi Queue (DEQUEUE)\n");
    printf("3. Menampilkan isi Queue -> FIFO\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan anda: ");
}

void display_queue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    node *current = q->head;
    while (current != NULL) {
        printf("Data: %c, Priority: %d\n", current->data, current->priority);
        current = current->next;
    }
}