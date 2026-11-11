#include <stdio.h>

struct Node{
	int data;
	struct Node *next;
};

int main(void){
	
	struct Node n1,n2,n3,n4;
	
	n1.data = 10;
	n1.next = &n2;
	n2.data = 20;
	n2.next = &n3;
	n3.data = 30;
	n3.next = &n4;
	n4.data = 40;
	n4.next = NULL;
	
	struct Node *head = &n1;
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));//yeni dügümü malloc ile olusturuyoruz
	newNode->data = 5;
	
	newNode->next = head;
	head = newNode;
	
	
	struct Node *current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
