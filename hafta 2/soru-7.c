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
	struct Node *current = head;
	int aranan_sayi = 30;
	int bulundumu = 0;
	
	while(current!=NULL){
		
		if(current->data==aranan_sayi){
			bulundumu=1;
			break;
		}
		
		current = current->next;
	}
	if(bulundumu==1){
		printf("%d dugumde vardır", aranan_sayi);
	}
	else{
		printf("%d dugumde yoktur", aranan_sayi);
	}
    return 0;  	
}
