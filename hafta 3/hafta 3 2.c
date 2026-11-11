#include <stdio.h>
 

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAt(Node** head, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int currentPosition = 0;

    while (current->next != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteAt(Node** head, int position) {
    if (*head == NULL || position < 0) {
        return;
    }

    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    int currentPosition = 0;

    while (current != NULL && current->next != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || current->next == NULL) {
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void) {
    Node* head = NULL;
    Node* current;
    Node* nextNode;

    insertAt(&head, 10, 0); 
    insertAt(&head, 20, 1); 
    insertAt(&head, 30, 5); 
    insertAt(&head, 5, -2); 
    printList(head); 

    deleteAt(&head, 0); 
    printList(head); 
    
    deleteAt(&head, 2); 
    printList(head); 
    
    deleteAt(&head, 99); 
    printList(head); 

    current = head;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = NULL;

    return 0;
} 
