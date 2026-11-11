#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song{
	char isim [50];
	struct Song *next;
	struct Song *prev;
}Song;

void sonaSarkiEkleme(Song** head, char* isim);
void sarkiSilme(Song** head, char* isim);
void sonrakiSarki(Song** current);
void oncekiSarki(Song** current);
void listeYazdirma(Song* head);

void sonaSarkiEkleme(Song **head, char *isim){
	
	Song *newSong = (Song*)malloc(sizeof(Song));
	strcpy(newSong->isim, isim);
	
	newSong->next = NULL;
	newSong->prev = NULL;
	
	if(*head==NULL){
		*head = newSong;
		return;
	}
	Song *current = *head;
	
	while(current->next!=NULL){
		current = current->next;
	}
	current->next = newSong;
	newSong->prev = current;
}

void sarkilariYazdir(Song* head) {//listeyi ekrana yazdirdigim fonksiyon
    if (head == NULL) {
        printf("Calma listesi su an bos.\n");
        return;
    }

    Song* current = head;
    printf("--- CALMA LISTESI ---\n");
    
    
    while (current != NULL) {
        printf("%s\n", current->isim);
        current = current->next; 
    }
}
void sarkiSilme(Song** head, char* isim) {
   
    if (*head == NULL) {
        printf("Liste bos! Silinecek sarki yok.\n");
        return;
    }
    
    if (strcmp((*head)->isim, isim) == 0) {
        Song* temp = *head;         
        *head = (*head)->next;     

        
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);                 
        printf("'%s' basariyla silindi.\n", isim);
        return;
    }

    Song* current = *head;
    
    while (current != NULL && strcmp(current->isim, isim) != 0) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("'%s' adli sarki listede bulunamadi.\n", isim);
        return;
    }
    current->prev->next = current->next;

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("'%s' basariyla silindi.\n", isim);
}

void sonrakiSarki(Song** current) {
    if (current == NULL || *current == NULL) {
        printf("Liste bos veya calan bir sarki yok!\n");
        return;
    }

    if ((*current)->next != NULL) {
        *current = (*current)->next;
        printf("Caliniyor: %s\n", (*current)->isim);
    } else {
        printf("Listenin sonundasiniz! Sonraki sarki yok. Calan: %s\n", (*current)->isim);
    }
}

void oncekiSarki(Song** current) {
    if (current == NULL || *current == NULL) {
        printf("Liste bos veya calan bir sarki yok!\n");
        return;
    }

    if ((*current)->prev != NULL) {
        *current = (*current)->prev;
        printf("Caliniyor: %s\n", (*current)->isim);
    } else {
        printf("Listenin basindasiniz! Onceki sarki yok. Calan: %s\n", (*current)->isim);
    }
}

void listeYazdirma(Song* head) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    printf("\n--- CALMA LISTESI ---\n");
    Song* temp = head;
    int index = 1;
    while (temp != NULL) {
        printf("%d. %s\n", index++, temp->isim);
        temp = temp->next;
    }
    printf("\n\n");
}

void listeyiTemizle(Song** head) {//bellek sizintisini onlemek icin yazdigimiz fonksiyon
    Song* current = *head;
    Song* nextSong = NULL;

    while (current != NULL) {
        nextSong = current->next; 
        free(current);           
        current = nextSong;       
    }

    *head = NULL; 
}
int main(void) {
    Song* head = NULL;
    Song* currentSong = NULL;
    int secim;
    char sarkiAdi[50];

    while (1) {
        printf("\n=== MUZIK CALAR MENUSU ===\n");
        printf("1. Sarki Ekle\n");
        printf("2. Sarki Sil\n");
        printf("3. Sonraki Sarkiya Gec (Next)\n");
        printf("4. Onceki Sarkiya Gec (Previous)\n");
        printf("5. Calma Listesini Goruntule\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        
        if (scanf("%d", &secim) != 1) {
            printf("Gecersiz giris yaptiniz!\n");
            break;
        }
        getchar(); // Enter karakterini temizle

        if (secim == 0) {
            listeyiTemizle(&head); // Cikis yapmadan once bellek temizligi
            printf("Muzik calar kapatildi.\n");
            break; // Donguden cik
        }

        switch (secim) {
            case 1:
                printf("Eklenecek sarki adi: ");
                fgets(sarkiAdi, sizeof(sarkiAdi), stdin);
                sarkiAdi[strcspn(sarkiAdi, "\n")] = '\0';
                sonaSarkiEkleme(&head, sarkiAdi);
                if (currentSong == NULL) {
                    currentSong = head;
                }
                break;
            case 2:
                printf("Silinecek sarki adi: ");
                fgets(sarkiAdi, sizeof(sarkiAdi), stdin);
                sarkiAdi[strcspn(sarkiAdi, "\n")] = '\0';
                sarkiSilme(&head, sarkiAdi);
                currentSong = head;
                break;
            case 3:
                sonrakiSarki(&currentSong);
                break;
            case 4:
                oncekiSarki(&currentSong);
                break;
            case 5:
                listeYazdirma(head);
                if (currentSong != NULL) {
                    printf("Su an calan sarki: %s\n", currentSong->isim);
                }
                break;
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
        }
    }

    return 0;
}
