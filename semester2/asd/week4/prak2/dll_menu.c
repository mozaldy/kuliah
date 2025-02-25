#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef char *String;
typedef int bool;

typedef struct dnode {
  int data;
  struct dnode *next, *prev;
} dnode;

void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();

void delete_awal();
void delete_akhir();
void delete_tertentu();

void tampil();
void alokasi();
void submenu(int);
void display_menu(int);

dnode *p, *head = NULL, *hapus;

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
    tampil();
  }
}

void display_menu(int input_menu) {
  printf("\n");
  if (input_menu == 0) {
    printf("Menu Utama\n");
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

void submenu(int menu_input) {
  int submenu_input;
  scanf("%d", &submenu_input);
  bool is_submenu = true;
  printf("\n");
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
        delete_awal();
        break;
      case 2:
        delete_akhir();
        break;
      case 3:
        delete_tertentu();
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

void alokasi() {
  p = malloc(sizeof(dnode));
  if (p == NULL) {
    printf("Memory tidak dapat dialokasikan!\n");
    exit(1);
  } else {
    p->next = NULL;
    p->prev = NULL;
    printf("Data yang mau disimpan? ");
    scanf("%d", &p->data);
    getchar();
  }
}

void tampil() {
  dnode *tampil = head;
  while (tampil != NULL) {
    printf("%d\n", tampil->data);
    tampil = tampil->next;
  }
}

void delete_awal() {
  hapus = head;
  head = hapus->next;

  free(hapus);
  hapus = NULL;
}

void delete_akhir() {
  hapus = head;
  while (hapus->next != NULL) {
    hapus = hapus->next;
  }

  hapus->prev->next = NULL;

  free(hapus);
  hapus = NULL;
}

void delete_tertentu() {
  int key;
  printf("Angka yang dihapus");
  scanf("%d", &key);
  if (key == head->data) {
    delete_awal();
    return;
  } else {
    hapus = head;
    while (hapus->data != key) {
      hapus = hapus->next;
      if (hapus == NULL) {
        printf("Key tidak ada.\n");
        exit(0);
      }
    }
  }

  hapus->prev->next = hapus->next;
  if (hapus->next != NULL) {
    hapus->next->prev = hapus->prev;
  }

  free(hapus);
  hapus = NULL;
}

void insert_awal() {
  if (head != NULL) {
    p->next = head;
    head->prev = p;
  }
  head = p;
}

void insert_akhir() {
  dnode *akhir = head;
  if (head == NULL) {
    head = p;
    return;
  } else {
    while (akhir->next != NULL) {
      akhir = akhir->next;
    }
  }
  akhir->next = p;
}

void insert_after() {
  int key;
  dnode *after = head;
  printf("Key ingin dimasukkan setelah angka berapa: ");
  scanf("%d", &key);
  while (after->data != key) {
    if (after->next == NULL) {
      printf("Key tersebut tidak ada dalam linked list!\n");
      exit(0);
    }
    after = after->next;
  }

  p->next = after->next;
  p->prev = after;
  if (after->next != NULL)
    after->next->prev = p;
  after->next = p;
}

void insert_before() {
  int key;
  dnode *before = head;
  printf("Key ingin dimasukkan sebelum angka berapa: ");
  scanf("%d", &key);
  if (before->data == key) {
    p->next = head;
    head = p;
    return;
  } else {
    while (before->data != key) {
      if (before->next == NULL) {
        printf("Key tersebut tidak ada dalam linked list!\n");
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
