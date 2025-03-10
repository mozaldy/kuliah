#include <stdio.h>
#include <stdlib.h>

typedef char typeInfo;
typedef struct tree {
  typeInfo info;
  struct tree *left, *right;
} tree;

tree *bentuk(typeInfo);
void sisip(tree *, tree **);

void main_input(tree **);
void main_kunjungan(tree **);
int menu_kunjungan();

void preorder(tree *);
void postorder(tree *);
void inorder(tree *);
tree *cari(tree *, int);

int main(int argc, char *argv[]) {
  tree *root = NULL;
  main_input(&root);
  main_kunjungan(&root);

  printf("\nMencari data dalam tree.\n");
  printf("Masukkan data yang dicari: ");
  char dicari = getchar();
  if (cari(root, dicari) == NULL)
    printf("%c tidak ada di dalam tree.\n", dicari);
  else
    printf("%c ada di dalam tree.\n", dicari);
}

void main_input(tree **root) {
  typeInfo info;
  tree *t;
  char input;
  printf("Membentuk sebuah tree\n");
  do {
    printf("Ketikkan data/infonya: ");
    info = getchar();
    getchar();
    t = bentuk(info);
    sisip(t, root);
    printf("Ada data lagi? (y/t): ");
    input = getchar();
    getchar();
  } while (input == 'y' || input == 'Y');
}

void main_kunjungan(tree **root) {
  char input;
  do {
    switch (menu_kunjungan()) {
    case 1:
      printf("Hasil penelusuran menggunakan preorder:\n");
      preorder(*root);
      break;
    case 2:
      printf("Hasil penelusuran menggunakan postorder:\n");
      postorder(*root);
      break;
    case 3:
      printf("Hasil penelusuran menggunakan inorder:\n");
      inorder(*root);
      break;
    }
    printf("\nMencoba metode lain? (y/t): ");
    getchar();
    input = getchar();
    getchar();
  } while (input == 'y' || input == 'Y');
}

int menu_kunjungan() {
  int pilihan, ulangi;
  do {
    printf("Pilih penelusuran tree\n");
    printf("1. PreOrder\n");
    printf("2. PostOrder\n");
    printf("3. InOrder\n");
    printf("Pilihan anda [1/2/3] : ");
    scanf("%d", &pilihan);
  } while (pilihan < 1 || pilihan > 3);
  return pilihan;
}

tree *bentuk(typeInfo info) {
  tree *t = malloc(sizeof(tree));
  if (t == NULL) {
    printf("Program gagal\n");
    exit(1);
  }
  t->info = info;
  t->left = NULL;
  t->right = NULL;
  return t;
}

void sisip(tree *t, tree **root) {
  if (*root == NULL)
    *root = t;
  else {
    tree *p, *q;
    p = q = *root;
    while (q != NULL && t->info != p->info) {
      p = q;
      if (t->info < p->info)
        q = p->left;
      else
        q = p->right;
    }
    if (t->info == p->info)
      return;
    else {
      if (t->info < p->info)
        p->left = t;
      else
        p->right = t;
    }
  }
}

void preorder(tree *root) {
  if (root != NULL) {
    printf("%c ", root->info);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(tree *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->info);
  }
}

void inorder(tree *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%c ", root->info);
    inorder(root->right);
  }
}

tree *cari(tree *root, int dicari) {
  if (root == NULL)
    return NULL;
  else if (dicari < root->info)
    return cari(root->left, dicari);
  else if (dicari > root->info)
    return cari(root->right, dicari);
  else
    return root;
}
