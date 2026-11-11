#include <stdio.h>

// 1. Düðüm kalýbýný tanýmlýyoruz
struct Node {
    int data;           // Saklanacak veri
    struct Node *next;  // Sonraki düðümün adresi[cite: 1]
};

int main(void) {
    // 2. Bir Node nesnesi oluþturuyoruz
    struct Node n1;

    // 3. Deðerleri atýyoruz
    n1.data = 10;
    n1.next = NULL; // Baþka düðüm olmadýðý için NULL gösterir[cite: 1]

    // 4. Veriyi ekrana yazdýrýyoruz[cite: 1]
    printf("Node icindeki veri: %d\n", n1.data);

    return 0;
}
