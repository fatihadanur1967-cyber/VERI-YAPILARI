#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int value) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node *insert(Node *root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void freeTree(Node *root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    Node *root = NULL;
    int degerler[] = {40, 20, 60, 10, 30, 50, 70};
    int n = sizeof(degerler) / sizeof(degerler[0]);
    int i;

    for (i = 0; i < n; i++)
        root = insert(root, degerler[i]);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
