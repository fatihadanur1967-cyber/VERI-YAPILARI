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
	n3.next = NULL;
	
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = 40;
	newNode->next = NULL;
	
	struct Node *head = &n1;
	struct Node *current = head;
	
	while(current->next!=NULL){
		current = current->next;
		
	}
	
	current->next = newNode;
	
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
	return 0;
}
