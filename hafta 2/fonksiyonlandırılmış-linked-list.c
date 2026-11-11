#include <stdio.h>


struct Node {
    int data;
    struct Node *next;
};


struct Node* insertBeginning(struct Node *head, int new_data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = new_data;
    
  
    newNode->next = head;
    head = newNode;      
    return head;
}


void display(struct Node *current) {
    printf("Liste: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


void search(struct Node *current, int aranan_sayi) {
    int bulundu = 0;
    
    while (current != NULL) {
        if (current->data == aranan_sayi) {
            bulundu = 1;
            break; 
        }
        current = current->next;
    }
    
    if (bulundu == 1) {
        printf("%d degeri listede BULUNDU.\n", aranan_sayi);
    } else {
        printf("%d degeri listede YOK.\n", aranan_sayi);
    }
}

int main(void) {
    
    struct Node *head = NULL; 

    
    head = insertBeginning(head, 30);
    head = insertBeginning(head, 20);
    head = insertBeginning(head, 10); 

    display(head);

    printf("\n--- Arama Sonuclari ---\n");
    
    search(head, 20); 
    search(head, 99); 

    return 0;
}
