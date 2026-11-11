#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

int height(Node* n) {
    return (n == NULL) ? 0 : n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getBalance(Node* n) {
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}

Node* createNode(int key) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        printf("Bellek ayrilamadi!\n");
        exit(1);
    }
    n->key = key;
    n->height = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* insertAVL(Node* root, int key) {
    int balance;

    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insertAVL(root->left, key);
    } else if (key > root->key) {
        root->right = insertAVL(root->right, key);
    } else {
        return root; 
    }

    root->height = 1 + max(height(root->left), height(root->right));

    balance = getBalance(root);

    if (balance > 1 && key < root->left->key) {
        printf("  [%d dugumunde dengesizlik: LL -> sag rotasyon]\n", root->key);
        return rotateRight(root);
    }

    if (balance < -1 && key > root->right->key) {
        printf("  [%d dugumunde dengesizlik: RR -> sol rotasyon]\n", root->key);
        return rotateLeft(root);
    }

    if (balance > 1 && key > root->left->key) {
        printf("  [%d dugumunde dengesizlik: LR -> sol + sag rotasyon]\n", root->key);
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && key < root->right->key) {
        printf("  [%d dugumunde dengesizlik: RL -> sag + sol rotasyon]\n", root->key);
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void runTest(char* ad, int keys[], int n) {
    Node* root = NULL;
    int i;

    printf("Test %s - Ekleme sirasi: ", ad);
    for (i = 0; i < n; i++) {
        printf("%d ", keys[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        root = insertAVL(root, keys[i]);
    }

    printf("  Kok degeri: %d\n", root->key);
    printf("  Preorder: ");
    preorder(root);
    printf("\n\n");

    freeTree(root);
}

int main(void) {
    int a[] = {30, 20, 10};
    int b[] = {10, 20, 30};
    int c[] = {30, 10, 20};
    int d[] = {10, 30, 20};

    runTest("A (LL)", a, 3);
    runTest("B (RR)", b, 3);
    runTest("C (LR)", c, 3);
    runTest("D (RL)", d, 3);

    return 0;
}
