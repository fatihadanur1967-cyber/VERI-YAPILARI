#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word {
    char text[50];
    struct Word* next;
} Word;

void pushWord(Word** top, char* text);
void popWord(Word** top);
void showWords(Word* top);

// Stack'e yeni kelime ekler 
void pushWord(Word** top, char* text) {
    Word* newWord = (Word*)malloc(sizeof(Word));
    if (newWord == NULL) {
        printf("Bellek ayrilamadi!\n");
        return;
    }
    strncpy(newWord->text, text, sizeof(newWord->text) - 1);
    newWord->text[sizeof(newWord->text) - 1] = '\0';

    newWord->next = *top;
    *top = newWord;
}

// En ustteki kelimeyi siler (undo) 
void popWord(Word** top) {
    if (*top == NULL) {
        printf("Geri alinacak kelime yok!\n");
        return;
    }
    Word* temp = *top;
    *top = (*top)->next;
    free(temp);
}

static void printReverse(Word* node) {
    if (node == NULL) {
        return;
    }
    printReverse(node->next);
    printf("%s ", node->text);
}

// Kelimeleri eklenme sirasina gore gosterir 
void showWords(Word* top) {
    if (top == NULL) {
        printf("Liste bos.\n");
        return;
    }
    printReverse(top);
    printf("\n");
}

//tum bellegý gýcýr gýcýr eder 
static void clearStack(Word** top) {
    while (*top != NULL) {
        popWord(top);
    }
}

int main(void) {
    Word* top = NULL;
    char line[100];
    char command[20];
    char word[50];

    printf("Komutlar: add <kelime>, undo, show, exit\n");

    while (1) {
        printf("> ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }
        line[strcspn(line, "\n")] = '\0';

        command[0] = '\0';
        word[0] = '\0';
        sscanf(line, "%19s %49s", command, word);

        if (strcmp(command, "add") == 0) {
            if (word[0] == '\0') {
                printf("Kullanim: add <kelime>\n");
            } else {
                pushWord(&top, word);
            }
        } else if (strcmp(command, "undo") == 0) {
            popWord(&top);
        } else if (strcmp(command, "show") == 0) {
            showWords(top);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else if (command[0] != '\0') {
            printf("Gecersiz komut!\n");
        }
    }

    clearStack(&top);
    return 0;
}
