
#include "stdio.h"
#include "stdlib.h"

typedef struct node {
  int data;
  struct node *next, *prev;
} node;

void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();

void delete_awal();
void delete_akhir();
void delete_tertentu();

void alokasi();
void tampil();
void menu(int);
void submenu(int);

node *p, *head = NULL;

int main(int argc, char *argv[]) {
  printf("Single Linked List - Insert\n");
  do {
    int user_input;
    menu(0);
    scanf("%d", &user_input);
    menu(user_input);
    submenu(user_input);
    tampil();
    printf("Ulangi lagi (y/t) ? ");
  } while (getchar() == 'y');
  tampil();
}

void submenu(int user_input) {

  int submenu_input;
  scanf("%d", &submenu_input);
  if (user_input == 1) {
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
      printf("User error.\n");
      break;
    }
  } else if (user_input == 2) {
    switch (submenu_input) {
    case 1:
      delete_awal();
      break;
    case 2:
      delete_akhir();
      break;
    case 3:
      delete_tertentu();
      break;
    default:
      printf("User error.\n");
      break;
    }
    getchar();
  }
}

void alokasi() {
  int angka;
  printf("Input angka: ");
  scanf("%d", &angka);
  getchar();
  p = malloc(sizeof(node));
  p->data = angka;
  p->next = NULL;
  p->prev = NULL;
}

void tampil() {
  node *head_copy = head;
  printf("\nData Linked List:\n");
  while (head_copy != NULL) {
    printf("%d\n", head_copy->data);
    head_copy = head_copy->next;
  }
  printf("\n");
}

void menu(int selected) {
  printf("\n");
  if (selected == 0) {
    printf("MENU SLL UTAMA\n");
    printf("1. Insert \n");
    printf("2. Delete \n");
    printf("3. Exit \n");
  } else if (selected == 1) {
    printf("MENU SLL INSERT\n");
    printf("1. Insert Awal\n");
    printf("2. Insert Akhir\n");
    printf("3. Insert After\n");
    printf("4. Insert Before\n");
  } else if (selected == 2) {
    printf("MENU SLL DELETE\n");
    printf("1. Delete Awal\n");
    printf("2. Delete Akhir\n");
    printf("3. Delete Tertentu\n");
  }
  printf("Input angka menu: ");
}

void insert_awal() {
  if (head != NULL) {
    head->prev = p;
  }
  p->next = head;
  head = p;
}

void insert_akhir() {
  node *tail = head;

  while (tail->next != NULL) {
    tail = tail->next;
  }

  if (head == NULL) {
    head = p;
  } else {
    p->prev = tail;
    tail->next = p;
  }
}

void insert_after() {
  int key;
  node *after = head;

  printf("Insert setelah angka: ");
  scanf("%d", &key);
  getchar();

  while (after->data != key) {
    if (after->next == NULL) {
      printf("Key tidak ada.\n");
      exit(0);
    }
    after = after->next;
  }

  p->prev = after;
  p->next = after->next;
  if (after->next != NULL)
    after->next->prev = p;

  after->next = p;
}

void insert_before() {
  int key;
  node *before = head;

  printf("Insert sebelum angka: ");
  scanf("%d", &key);
  getchar();

  if (before->data == key) {
    insert_awal();
    return;
  } else {

    while (before->data != key) {
      if (before->next == NULL) {
        printf("Key tidak ada.\n");
        exit(0);
      }
      before = before->next;
    }
  }

  p->next = before;
  p->prev = before->prev;
  if (before->prev != NULL)
    before->prev->next = p;

  before->prev = p;
}

void delete_awal() {
  node *hapus = head;

  head = head->next;

  free(hapus);
  hapus = NULL;
  printf("\nDeleted!\n");
}

void delete_akhir() {
  node *hapus = head, *prev_hapus;
  if (hapus->next == NULL) {
    delete_awal();
    return;
  } else {
    while (hapus->next != NULL) {
      prev_hapus = hapus;
      hapus = hapus->next;
    }
  }

  prev_hapus->next = NULL;

  free(hapus);
  hapus = NULL;
}

void delete_tertentu() {
  int key;
  node *hapus = head, *prev_hapus;
  printf("Angka yang dihapus: ");
  scanf("%d", &key);
  if (hapus->data == key) {
    delete_awal();
    return;
  } else {
    while (hapus->data != key) {
      if (hapus->next == NULL) {
        printf("Key tidak ada\n");
        exit(0);
      }
      prev_hapus = hapus;
      hapus = hapus->next;
    }

    prev_hapus->next = hapus->next;

    free(hapus);
    hapus = NULL;
  }
}
