#include <stdio.h>

struct Node {
	int data;
	struct Node *next;
};

int main (void){
	
	// üç düðüm için bellekten yer ayýrýyoruz malloc fonksiyonu ile
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 10;
    head->next = second;
    
    second->data = 20;
    second->next = third;
    
    third->data = 30;
    third->next = NULL;
    
    struct Node *current = head;
    while(current!= NULL){
    	printf("%d-> ", current->data);
    	current = current->next;
	}
	printf("Null\n");
	
	//yer yrýlan bellekleri sýzýntý olmasýn diye serbest býrakýyorum
	free(head);
	free(second);
	free(third);
	
	
	return 0;
}
