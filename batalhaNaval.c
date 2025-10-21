#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro 10x10
#define AGUA 0       // Representa água
#define NAVIO 3      // Representa navio
#define TAM_NAVIO 3  // Tamanho fixo de cada navio

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // === 1. Inicializar o tabuleiro com 0 (água) ===
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // === 2. Posicionar 4 navios ===
    // Dois horizontais/verticais e dois em diagonal

    // Navio 1 - horizontal
    int linha1 = 2, coluna1 = 4;
    for (j = coluna1; j < coluna1 + TAM_NAVIO && j < TAM; j++) {
        tabuleiro[linha1][j] = NAVIO;
    }

    // Navio 2 - vertical
    int linha2 = 6, coluna2 = 1;
    for (i = linha2; i < linha2 + TAM_NAVIO && i < TAM; i++) {
        tabuleiro[i][coluna2] = NAVIO;
    }

    // Navio 3 - diagonal principal (↘)
    int linha3 = 1, coluna3 = 1;
    for (i = 0; i < TAM_NAVIO; i++) {
        if (linha3 + i < TAM && coluna3 + i < TAM)
            tabuleiro[linha3 + i][coluna3 + i] = NAVIO;
    }

    // Navio 4 - diagonal secundária (↙)
    int linha4 = 5, coluna4 = 8;
    for (i = 0; i < TAM_NAVIO; i++) {
        if (linha4 + i < TAM && coluna4 - i >= 0)
            tabuleiro[linha4 + i][coluna4 - i] = NAVIO;
    }

    // === 3. Exibir o tabuleiro ===
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}