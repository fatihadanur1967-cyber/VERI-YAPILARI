#include <stdio.h>


struct Node {
    int data;           
    struct Node *next;  
};

int main(void) {
    
    struct Node n1;
    struct Node n2;

    
    n1.data = 10; 
    n2.data = 20;
    n1.next = &n2;
    n2.next = NULL;


    
    printf("n1'in verisi: %d \n n1'in baglandigi dugumun verisi: %d\n", n1.data, n1.next->data);

    return 0;
}
