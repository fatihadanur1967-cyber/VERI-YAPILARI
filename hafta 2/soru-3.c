#include <stdio.h>

struct Node {
	int data;
	struct Node *next;
};

int main(void){
	
	struct Node n1 ,n2 ,n3;
	
	n1.data = 10;
	n2.data = 20;
	n3.data = 30;
	
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
	
	struct Node *head = &n1;
	struct Node *current = head;
	
	while(current != NULL){
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
	
	return 0;
}
