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

void preorder(tree *);
void postorder(tree *);
void inorder(tree *);


int main() {
  tree *root = NULL; // inisialisasi akar tree
  char expression[100]; // inisialisasi ekspresi yang diinputkan user

  printf("Masukkan ekspresi aritmatika dalam notasi infix: ");
  fgets(expression, sizeof(expression), stdin);

  size_t len = strlen(expression); // menggunakan length dari string untuk pembatasan iterasi
 if (len > 0 && expression[len - 1] == '\n') { // memastikan bahwa end of string bukan newline
    expression[len - 1] = '\0';
  }

  parseInfixExpression(expression, &root); // jalankan algoritma infix

  printf("\nPreorder traversal:\n");
  preorder(root);
  printf("\n\nInorder traversal:\n");
  inorder(root);
  printf("\n\nPostorder traversal:\n");
  postorder(root);
  printf("\n");

  return 0;
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
  stack stOperator = {NULL}; // inisialisasi stack operator
  stack stOperan = {NULL}; // inisialisasi stack operan

  int length = strlen(expression); // sama kayak yang di main tapi newline pasti sudah di purge
  for (int i = 0; i < length; ++i) {
    char R = expression[i];

    if (R == '(') {
      push(&stOperator, bentuk(R)); // kurung buka di push ke stack operator
    } else if ((R >= 'a' && R <= 'z') || (R >= 'A' && R <= 'Z') ||
               (R >= '0' && R <= '9')) {
      push(&stOperan, bentuk(R)); // Alfabet & angka dipush ke stack operan
    } else if (R == '+' || R == '-' || R == '*' || R == '/') {
      push(&stOperator, bentuk(R)); // Simbol operasi perhitungan di push ke stack operator
    } else if (R == ')') { // apabika char adalah kurung tutup, maka semua yang ada di stack di pop
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
