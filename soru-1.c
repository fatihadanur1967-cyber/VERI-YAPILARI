#include <stdio.h>

#define MAX 20


#define N 6
int kenarlar[][2] = { {1, 2}, {1, 4}, {2, 3}, {3, 4}, {3, 6}, {4, 5}, {5, 6} };

int mat[MAX][MAX];    
int n = N;

void matrisiSifirla(void) {
    int i, j;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            mat[i][j] = 0;
}

void baglantiEkle(int a, int b) {
    mat[a - 1][b - 1] = 1;
    mat[b - 1][a - 1] = 1;
}


void matrisYazdir(void) {
    int i, j;
    printf("Komsuluk matrisi:\n    ");
    for (j = 0; j < n; j++)
        printf("%d ", j + 1);
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%2d: ", i + 1);
        for (j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}


void dereceHesapla(void) {
    int i, j, d;
    int toplam = 0, maks = 0;

    printf("Dugum dereceleri:\n");
    for (i = 0; i < n; i++) {
        d = 0;
        for (j = 0; j < n; j++)
            d += mat[i][j];
        printf("  Dugum %d: %d\n", i + 1, d);
        toplam += d;
        if (d > maks)
            maks = d;
    }
    printf("Grafin toplam derecesi: %d (kenar sayisi: %d)\n", toplam, toplam / 2);
    printf("Grafin maksimum derecesi: %d\n", maks);
}


int bipartiteKontrol(void) {
    int renk[MAX], mesafe[MAX], kuyruk[MAX];
    int bas, son, s, u, v, i;
    int bipartite = 1;

    for (i = 0; i < n; i++) {
        renk[i] = -1;
        mesafe[i] = -1;
    }

    for (s = 0; s < n; s++) {         
        if (renk[s] != -1)
            continue;                 

        renk[s] = 0;
        mesafe[s] = 0;
        bas = 0;
        son = 0;
        kuyruk[son++] = s;

        while (bas < son) {
            u = kuyruk[bas++];
            for (v = 0; v < n; v++) {
                if (mat[u][v] == 0)
                    continue;

                if (renk[v] == -1) {
                    renk[v] = 1 - renk[u];
                    mesafe[v] = mesafe[u] + 1;
                    kuyruk[son++] = v;
                } else if (renk[v] == renk[u]) {
                    if (u < v)
                        printf("Celiski: %d ve %d komsu ama ayni renkte.\n", u + 1, v + 1);
                    bipartite = 0;
                }
            }
        }
    }

    printf("Dugum  Uzaklik  Renk\n");
    for (i = 0; i < n; i++)
        printf("%4d  %7d  %s\n", i + 1, mesafe[i], renk[i] == 0 ? "0 (Mavi)" : "1 (Kirmizi)");

    
    if (bipartite) {
        printf("U (Istemciler, renk 0):");
        for (i = 0; i < n; i++)
            if (renk[i] == 0)
                printf(" %d", i + 1);
        printf("\nV (Sunucular, renk 1):");
        for (i = 0; i < n; i++)
            if (renk[i] == 1)
                printf(" %d", i + 1);
        printf("\n");
    }

    return bipartite;
}

void rapor(void) {
    matrisYazdir();
    printf("\n");
    dereceHesapla();
    printf("\n");
    if (bipartiteKontrol())
        printf("Sonuc: Graf IKI PARCALI (bipartite).\n");
    else
        printf("Sonuc: Graf IKI PARCALI DEGIL.\n");
}

int main(void) {
    int i;
    int m = sizeof(kenarlar) / sizeof(kenarlar[0]);

    matrisiSifirla();
    for (i = 0; i < m; i++)
        baglantiEkle(kenarlar[i][0], kenarlar[i][1]);

    printf("===== BASLANGIC GRAFI =====\n");
    rapor();


    printf("\n===== (2, 4) baglantisi eklendi =====\n");
    baglantiEkle(2, 4);
    rapor();

    return 0;
}

/* GOREV 4 ACIKLAMASI:
   Baslangicta graf bipartite: U = {1, 3, 5} (Mavi), V = {2, 4, 6} (Kirmizi) ve
   butun kenarlar iki kume arasindadir. 2 ve 4 numarali dugumler ikisi de V
   kumesindedir (ayni renk). (2, 4) kenari eklenince ayni kumedeki iki dugum
   dogrudan baglanmis olur; bu, senaryodaki "kendi kumesi icindeki cihazlar
   birbirine baglanamaz" kuralini ihlal eder. Graf teorisi acisindan 1-2-4 ve
   2-3-4 ucgenleri (tek uzunluklu cevrimler) olusur ve tek uzunluklu cevrim
   iceren graf bipartite olamaz. Sonuc "iki parcali" iken "iki parcali degil"e
   doner. Ayrica 2 ve 4'un dereceleri 1'er artar, toplam derece 14'ten 16'ya,
   kenar sayisi 7'den 8'e cikar.
*/