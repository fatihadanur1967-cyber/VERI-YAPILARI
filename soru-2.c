#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

#define N 6
#define INF 1000000




struct Kenar {
    char a, b;
    int w;
};

struct Kenar kenarlar[] = {
    {'A', 'B', 7}, {'A', 'C', 5}, {'A', 'F', 1},
    {'B', 'C', 1}, {'B', 'D', 1}, {'B', 'E', 3},
    {'C', 'D', 2}, {'C', 'E', 1},
    {'D', 'F', 7},
    {'E', 'F', 2}
};

int agirlik[N][N];   

void grafiKur(void) {
    int i, j;
    int m = sizeof(kenarlar) / sizeof(kenarlar[0]);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            agirlik[i][j] = 0;

    for (i = 0; i < m; i++) {
        int u = kenarlar[i].a - 'A';
        int v = kenarlar[i].b - 'A';
        agirlik[u][v] = kenarlar[i].w;
        agirlik[v][u] = kenarlar[i].w;
    }
}


void tabloYazdir(int adim, int secilen, int known[], int dist[], int path[]) {
    int i;
    printf("Adim %d: secilen dugum %c\n", adim, 'A' + secilen);
    printf("Dugum  Known  Distance  Path\n");
    for (i = 0; i < N; i++) {
        printf("  %c      %d     ", 'A' + i, known[i]);
        if (dist[i] >= INF)
            printf("  INF     ");
        else
            printf("  %3d     ", dist[i]);
        if (path[i] == -1)
            printf("-\n");
        else
            printf("%c\n", 'A' + path[i]);
    }
    printf("\n");
}


void dijkstra(int kok, int dist[], int path[], int goster) {
    int known[N];
    int i, adim, u, v;

    for (i = 0; i < N; i++) {
        known[i] = 0;
        dist[i] = INF;
        path[i] = -1;
    }
    dist[kok] = 0;

    for (adim = 1; adim <= N; adim++) {
       
        u = -1;
        for (i = 0; i < N; i++)
            if (!known[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        if (u == -1 || dist[u] >= INF)
            break;

        known[u] = 1;

       
        for (v = 0; v < N; v++) {
            if (agirlik[u][v] > 0 && !known[v] && dist[u] + agirlik[u][v] < dist[v]) {
                dist[v] = dist[u] + agirlik[u][v];
                path[v] = u;
            }
        }

        if (goster)
            tabloYazdir(adim, u, known, dist, path);
    }
}


void rotaYazdir(int kok, int hedef, int dist[], int path[]) {
    int v;
    int ilk;

    printf("%c dugumune en kisa yol (toplam maliyet %d)\n", 'A' + hedef, dist[hedef]);

    printf("  Tersten okuma: ");
    ilk = 1;
    for (v = hedef; v != -1; v = path[v]) {
        if (!ilk)
            printf(" <- ");
        printf("%c", 'A' + v);
        ilk = 0;
    }
    printf("\n");

    printf("  Rota:          ");
   
    {
        int yol[N], uzunluk = 0, i;
        for (v = hedef; v != -1; v = path[v])
            yol[uzunluk++] = v;
        for (i = uzunluk - 1; i >= 0; i--) {
            printf("%c", 'A' + yol[i]);
            if (i > 0)
                printf(" -> ");
        }
    }
    printf("\n");
    (void)kok;
}

void merkeziDugumBul(void) {
    int toplam[N];
    int dist[N], path[N];
    int k, i, enKucuk;

    printf("Dugum  Toplam maliyet (diger dugumlere en kisa yol toplami)\n");
    for (k = 0; k < N; k++) {
        dijkstra(k, dist, path, 0);
        toplam[k] = 0;
        for (i = 0; i < N; i++)
            toplam[k] += dist[i];
        printf("  %c    %d\n", 'A' + k, toplam[k]);
    }

    enKucuk = toplam[0];
    for (k = 1; k < N; k++)
        if (toplam[k] < enKucuk)
            enKucuk = toplam[k];

    printf("\nEn dusuk toplam maliyet: %d\n", enKucuk);
    printf("En merkezi dugum(ler):");
    for (k = 0; k < N; k++)
        if (toplam[k] == enKucuk)
            printf(" %c", 'A' + k);
    printf("\n");
}

int main(void) {
    int dist[N], path[N];
    char harf;
    int kok, i;

    grafiKur();

    printf("Kok dugumu giriniz (A-F): ");
    if (scanf(" %c", &harf) != 1) {
        printf("Gecersiz giris!\n");
        return 1;
    }
    harf = (char)toupper((unsigned char)harf);
    if (harf < 'A' || harf > 'F') {
        printf("Gecersiz dugum! A ile F arasinda bir harf girin.\n");
        return 1;
    }
    kok = harf - 'A';

    printf("\n===== DIJKSTRA TABLOSU (kok: %c) =====\n\n", harf);
    dijkstra(kok, dist, path, 1);

    printf("===== ROTA CIKTISI (kok: %c) =====\n", harf);
    for (i = 0; i < N; i++) {
        if (i == kok)
            continue;
        rotaYazdir(kok, i, dist, path);
    }

    printf("\n===== MERKEZI DUGUM TESPITI =====\n");
    merkeziDugumBul();

    return 0;
}