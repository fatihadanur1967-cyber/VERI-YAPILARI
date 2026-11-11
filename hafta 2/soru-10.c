#include <stdio.h>


struct Node {
    int data;
    struct Node *next;
};

int main(void) {
    // free kullanabýlmek ýcýn malloc kullanýyoruz
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 10;      head->next = second;
    second->data = 20;    second->next = third;
    third->data = 30;     third->next = fourth;
    fourth->data = 40;    fourth->next = NULL;

    printf("Silmeden once: ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    int silinecek_sayi = 30;
    struct Node *current = head;
    struct Node *previous = NULL;

    while (current != NULL && current->data != silinecek_sayi) {
        previous = current;      
        current = current->next;  
    }

    
    if (current != NULL) {
        previous->next = current->next; 
        
        free(current); 
        printf("\n[%d degeri listeden silindi]\n\n", silinecek_sayi);
    } else {
        printf("\n[%d listede bulunamadi]\n\n", silinecek_sayi);
    }

    printf("Sildikten sonra: ");
    temp = head; // tempi tekrar baþa aldýk
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
