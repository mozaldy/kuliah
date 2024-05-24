#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char typeInfo;
typedef struct tree {
  typeInfo info;
  struct tree *left, *right;
} tree;

typedef struct stackNode {
  tree *node;
  struct stackNode *next;
} stackNode;

typedef struct stack {
  stackNode *top;
} stack;

tree *bentuk(typeInfo);
void sisip(tree *, tree **);
void push(stack *, tree *);
tree *pop(stack *);
bool isEmpty(stack *);
void parseInfixExpression(const char *expression, tree **root);

void main_input(tree **);
void main_kunjungan(tree **);
int menu_kunjungan();

void preorder(tree *);
void postorder(tree *);
void inorder(tree *);
tree *cari(tree *, int);

int main() {
  tree *root = NULL;
  char expression[100];

  printf("Masukkan ekspresi aritmatika dalam notasi infix: ");
  fgets(expression, sizeof(expression), stdin);

  size_t len = strlen(expression);
  if (len > 0 && expression[len - 1] == '\n') {
    expression[len - 1] = '\0';
  }

  parseInfixExpression(expression, &root);

  printf("\nPreorder traversal:\n");
  preorder(root);
  printf("\n\nInorder traversal:\n");
  inorder(root);
  printf("\n\nPostorder traversal:\n");
  postorder(root);
  printf("\n");

  return 0;
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
  int pilihan;
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
  tree *t = (tree *)malloc(sizeof(tree));
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
  if (*root == NULL) {
    *root = t;
  } else {
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

void push(stack *s, tree *node) {
  stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
  if (newNode == NULL) {
    printf("Stack overflow\n");
    exit(1);
  }
  newNode->node = node;
  newNode->next = s->top;
  s->top = newNode;
}

tree *pop(stack *s) {
  if (isEmpty(s)) {
    printf("Stack underflow\n");
    exit(1);
  }
  stackNode *temp = s->top;
  tree *node = temp->node;
  s->top = s->top->next;
  free(temp);
  return node;
}

bool isEmpty(stack *s) { return s->top == NULL; }

void parseInfixExpression(const char *expression, tree **root) {
  stack stOperator = {NULL};
  stack stOperan = {NULL};

  int length = strlen(expression);
  for (int i = 0; i < length; ++i) {
    char R = expression[i];

    if (R == '(') {
      push(&stOperator, bentuk(R));
    } else if ((R >= 'a' && R <= 'z') || (R >= 'A' && R <= 'Z') ||
               (R >= '0' && R <= '9')) {
      push(&stOperan, bentuk(R));
    } else if (R == '+' || R == '-' || R == '*' || R == '/') {
      push(&stOperator, bentuk(R));
    } else if (R == ')') {
      while (!isEmpty(&stOperator) && stOperator.top->node->info != '(') {
        tree *operatorNode = pop(&stOperator);
        operatorNode->right = pop(&stOperan);
        operatorNode->left = pop(&stOperan);
        push(&stOperan, operatorNode);
      }
      if (!isEmpty(&stOperator) && stOperator.top->node->info == '(') {
        pop(&stOperator);
      }
    }
  }

  while (!isEmpty(&stOperator)) {
    tree *operatorNode = pop(&stOperator);
    operatorNode->right = pop(&stOperan);
    operatorNode->left = pop(&stOperan);
    push(&stOperan, operatorNode);
  }

  if (!isEmpty(&stOperan)) {
    *root = pop(&stOperan);
  }
}
