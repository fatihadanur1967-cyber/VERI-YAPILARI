#include <stdio.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

void addOrdered(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void removeNode(Node** head, int value) {
    if (*head == NULL) return;

    if ((*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

int count(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void clear(Node** head) {
    Node* current = *head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *head = NULL;
}

int main(void) {
    Node* head = NULL;

    int sayilar[] = {23, 11, 5, 9, 6, 4, 12, 24};
    int n = sizeof(sayilar) / sizeof(sayilar[0]);

    int i;
    for (i = 0; i < n; i++) {
        addOrdered(&head, sayilar[i]);
    }
    printList(head);
    
    removeNode(&head, 11);
    printList(head);

    clear(&head);
    printList(head);

    return 0;
}
