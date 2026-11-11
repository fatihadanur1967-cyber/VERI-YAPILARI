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
	
	int sum = 0;
	struct Node *head = &n1;
	struct Node *current = head;
	
	while (current!=NULL){
		sum = sum + current->data;
		current =current->next;
	}
	printf("dugumdeki degerlerin toplami %d", sum);
	return 0;
}
