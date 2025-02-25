#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef struct node {
  int number;
  struct node *next;
} node;

void alokasi();
void display();
void display_menu(int);
void submenu(int);
void bebas();

void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();

void hapus_awal();
void hapus_akhir();
void hapus_tertentu();

node *head = NULL, *p;

int main(int argc, char *argv[]) {
  bool is_menu = true;
  int menu_input;
  while (is_menu) {
    display_menu(0);
    scanf("%d", &menu_input);
    if (menu_input == 1 || menu_input == 2) {
      display_menu(menu_input);
    } else if (menu_input == 3) {
      printf("Keluar\n");
      return 0;
    } else {
      printf("Input tidak valid!\n");
    }
    submenu(menu_input);
  }
}

void submenu(int menu_input) {
  int submenu_input;
  scanf("%d", &submenu_input);
  bool is_submenu = true;
  while (is_submenu) {
    if (menu_input == 1) {
      is_submenu = false;
      alokasi();
      switch (submenu_input) {
      case 1:
        insert_awal();
        break;
      case 2:
        insert_akhir();
        break;
      case 3:
        insert_after();
        break;
      case 4:
        insert_before();
        break;
      default:
        printf("Input tidak valid!\n");
        break;
      }

    } else {
      printf("Delete\n");
      is_submenu = false;
      if (head == NULL)
        submenu_input = 4;
      switch (submenu_input) {
      case 1:
        hapus_awal();
        break;
      case 2:
        hapus_akhir();
        break;
      case 3:
        hapus_tertentu();
        break;
      case 4:
        printf("List masih kosong!\n");
        break;
      default:
        printf("Input tidak valid!\n");
        break;
      }
    }
  }
}

void display_menu(int input_menu) {
  display();
  if (input_menu == 0) {
    printf("Menu SSL\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Exit\n");
  } else if (input_menu == 1) {
    printf("Menu Insert\n");
    printf("1. Awal\n");
    printf("2. Akhir\n");
    printf("3. After\n");
    printf("4. Before\n");
  } else {
    printf("Menu Delete\n");
    printf("1. Awal\n");
    printf("2. Akhir\n");
    printf("3. Tertentu\n");
  }
  printf("Masukkan pilihan anda: ");
}

void alokasi() {
  int number;

  printf("Input angka: ");
  scanf("%d", &number);

  p = (node *)malloc(sizeof(node));

  if (p != NULL) {
    p->number = number;
    p->next = NULL;
  } else {
    exit(1);
  }
}

void insert_awal() {
  if (head != NULL) {
    p->next = head;
  }
  head = p;
}

void insert_akhir() {
  if (head == NULL) {
    head = p;
  } else {
    for (node *ptr = head; ptr != NULL; ptr = ptr->next) {
      if (ptr->next == NULL) {
        ptr->next = p;
        break;
      }
    }
  }
}

void insert_after() {
  int key;

  if (head == NULL) {
    printf("No list available!\n");
  }

  printf("Disisipkan setelah angka berapa? ");
  scanf("%d", &key);

  node *after;
  for (after = head; after->number != key; after = after->next) {
    if (after->next == NULL) {
      printf("Nilai %d tidak ada di dalam list!\n", key);
      exit(0);
    }
  }
  p->next = after->next;
  after->next = p;
}

void insert_before() {
  int key;

  if (head == NULL) {
    printf("No list available!\n");
  }

  printf("Disisipkan sebelum angka berapa? ");
  scanf("%d", &key);

  if (head->number == key) {
    p->next = head;
    head = p;
    return;
  }

  node *before, *prev_before;
  for (before = head; before != NULL && before->number != key;
       before = before->next) {
    prev_before = before;
  }

  if (before == NULL) {
    printf("Nilai %d tidak ada di dalam list!\n", key);
    free(p);
    return;
  }

  p->next = before;
  prev_before->next = p;
}

void hapus_awal() {
  if (head == NULL)
    return;

  node *hapus = head;
  head = head->next;
  free(hapus);
}

void hapus_akhir() {
  if (head == NULL)
    return;

  node *hapus = head;
  node *prev_hapus = NULL;

  while (hapus->next != NULL) {
    prev_hapus = hapus;
    hapus = hapus->next;
  }

  if (prev_hapus == NULL) {
    free(hapus);
    head = NULL;
  } else {
    prev_hapus->next = NULL;
    free(hapus);
  }
}

void hapus_tertentu() {
  int key;
  node *hapus = head;
  node *prev_hapus = NULL;

  printf("Angka yang ingin dihapus: ");
  scanf("%d", &key);

  if (hapus != NULL && hapus->number == key) {
    head = hapus->next;
    free(hapus);
    return;
  }

  while (hapus != NULL && hapus->number != key) {
    prev_hapus = hapus;
    hapus = hapus->next;
  }

  if (hapus == NULL)
    return;

  prev_hapus->next = hapus->next;

  free(hapus);
}

void display() {
  node *head_copy;
  printf("\n");
  for (head_copy = head; head_copy != NULL; head_copy = head_copy->next) {
    printf("%i\n", head_copy->number);
  }
}
void bebas() {
  while (head != NULL) {
    node *tmp = head->next;
    free(head);
    head = tmp;
  }
}
