#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona manualmente dois navios (exemplo)
    // Navio 1 - horizontal
    int linha1 = 2, coluna1 = 4;
    for (j = coluna1; j < coluna1 + TAM_NAVIO; j++) {
        tabuleiro[linha1][j] = 3;
    }

    // Navio 2 - vertical
    int linha2 = 6, coluna2 = 1;
    for (i = linha2; i < linha2 + TAM_NAVIO; i++) {
        tabuleiro[i][coluna2] = 3;
    }

    // Exibe o tabuleiro
    printf("=== TABULEIRO ===\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}