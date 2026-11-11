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


int search(Node *root, int value) {
    if (root == NULL)
        return 0;
    if (value == root->data)
        return 1;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}

int findMin(Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int main() {
    Node* root = NULL;
    int numbers[] = {40, 20, 60, 10, 30, 50, 70};
    int i;

    for (i = 0; i < 7; i++)
        root = insert(root, numbers[i]);

    if (search(root, 30))
        printf("30 agacta bulundu.\n");
    else
        printf("30 agacta bulunamadi.\n");

    if (search(root, 90))
        printf("90 agacta bulundu.\n");
    else
        printf("90 agacta bulunamadi.\n");

    if (root != NULL)
        printf("En kucuk eleman: %d\n", findMin(root));

    freeTree(root);
    return 0;
}
/*
  KISA DEGERLENDIRME SORULARI

  1) 25 eklenirse hangi dugumun altina yerlesir?
  
     25 40tan kucuk oldugu icin sola, 20den buyuk oldugu icin
     saga, 30dan kucuk oldugu icin tekrar sola gider. 30un sol tarafýnda kalýr
     
  2) inorder'da printf ilk satira tasinirsa hangi dolasma elde edilir?
  
     Preorder (kok-sol-sag). cýktý: 40 20 10 30 60 50 70

  3) findMinde left yerine right izlenirse ne bulunur?
     En buyuk deger olan 70 bulunur
*/
