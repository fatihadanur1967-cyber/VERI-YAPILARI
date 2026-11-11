#include <stdio.h>
 

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* findMiddle(Node* head) {
  
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      
        fast = fast->next->next; 
    }

    
    return slow;
}


void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


void append(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int main(void) {
    Node* head = NULL;
    Node* middle = NULL;


    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    printf("Tek sayida elemanli liste:\n");
    printList(head);
    
    middle = findMiddle(head);
    if (middle != NULL) {
        printf("Ortadaki dugum: %d\n\n", middle->data);
    }

   
    append(&head, 60);

    printf("Cift sayida elemanli liste:\n");
    printList(head);
    
    middle = findMiddle(head);
    if (middle != NULL) {
        
        printf("Ortadaki dugum (ikincisi): %d\n\n", middle->data);
    }

    
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current); 
        current = nextNode;
    }
    head = NULL;
    
    printf("Tum dugumler 'free' ile bellekten temizlendi.\n");

    return 0;
}
