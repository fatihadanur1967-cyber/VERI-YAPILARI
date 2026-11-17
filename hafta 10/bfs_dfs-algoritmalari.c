#include <stdio.h>

#define N 5

enum { ISTANBUL, ANKARA, IZMIR, BURSA, ANTALYA };

const char *sehir[N] = {"Istanbul", "Ankara", "Izmir", "Bursa", "Antalya"};

int graf[N][N];

void baglantiEkle(int a, int b) {
    graf[a][b] = 1;
    graf[b][a] = 1;
}

void bfs(int baslangic) {
    int ziyaret[N] = {0};
    int kuyruk[N];
    int bas = 0, son = 0;
    int simdiki, i;
    int ilk = 1;

    ziyaret[baslangic] = 1;
    kuyruk[son++] = baslangic;

    printf("BFS: ");
    while (bas < son) {
        simdiki = kuyruk[bas++];

        if (!ilk)
            printf(" -> ");
        printf("%s", sehir[simdiki]);
        ilk = 0;

        for (i = 0; i < N; i++) {
            if (graf[simdiki][i] == 1 && !ziyaret[i]) {
                ziyaret[i] = 1;
                kuyruk[son++] = i;
            }
        }
    }
    printf("\n");
}

void dfsYardimci(int sehirNo, int ziyaret[], int *ilk) {
    int i;

    ziyaret[sehirNo] = 1;
    if (!(*ilk))
        printf(" -> ");
    printf("%s", sehir[sehirNo]);
    *ilk = 0;

    for (i = 0; i < N; i++) {
        if (graf[sehirNo][i] == 1 && !ziyaret[i])
            dfsYardimci(i, ziyaret, ilk);
    }
}

void dfs(int baslangic) {
    int ziyaret[N] = {0};
    int ilk = 1;

    printf("DFS: ");
    dfsYardimci(baslangic, ziyaret, &ilk);
    printf("\n");
}

int main(void) {
    /* Sorudaki baglantilar */
    baglantiEkle(ISTANBUL, ANKARA);
    baglantiEkle(ISTANBUL, BURSA);
    baglantiEkle(ANKARA, IZMIR);
    baglantiEkle(ANKARA, ANTALYA);
    baglantiEkle(BURSA, ANTALYA);

    bfs(ISTANBUL);
    dfs(ISTANBUL);

    return 0;
}