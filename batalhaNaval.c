#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5  // Tamanho da matriz de habilidade (exemplo: 5x5)
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// ==== Função para exibir qualquer matriz ====
void exibirMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// ==== Função para exibir uma matriz de habilidade (ex: 5x5) ====
void exibirHabilidade(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// ==== Cria habilidade em formato de cone ====
void criarCone(int hab[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Parte superior (ápice do cone) é 0, depois vai expandindo
            if (j >= (TAM_HAB/2 - i) && j <= (TAM_HAB/2 + i))
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

// ==== Cria habilidade em formato de cruz ====
void criarCruz(int hab[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB/2 || j == TAM_HAB/2)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

// ==== Cria habilidade em formato de octaedro (losango) ====
void criarOctaedro(int hab[TAM_HAB][TAM_HAB]) {
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

// ==== Aplica uma habilidade no tabuleiro ====
void aplicarHabilidade(int tab[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int origemX, int origemY) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (hab[i][j] == 1) {
                int x = origemX - offset + i;
                int y = origemY - offset + j;

                // Garante que não sai do tabuleiro
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    // Marca com o valor da habilidade sem apagar o navio
                    if (tab[x][y] != NAVIO)
                        tab[x][y] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int habCone[TAM_HAB][TAM_HAB];
    int habCruz[TAM_HAB][TAM_HAB];
    int habOctaedro[TAM_HAB][TAM_HAB];
    int i, j;

    // === Inicializa o tabuleiro com água ===
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // === Posiciona alguns navios ===
    for (j = 2; j < 5; j++) tabuleiro[2][j] = NAVIO; // horizontal
    for (i = 6; i < 9; i++) tabuleiro[i][1] = NAVIO; // vertical

    // === Cria as habilidades ===
    criarCone(habCone);
    criarCruz(habCruz);
    criarOctaedro(habOctaedro);

    printf("=== Habilidade: Cone ===\n");
    exibirHabilidade(habCone);
    printf("\n=== Habilidade: Cruz ===\n");
    exibirHabilidade(habCruz);
    printf("\n=== Habilidade: Octaedro ===\n");
    exibirHabilidade(habOctaedro);

    // === Aplica habilidades no tabuleiro ===
    aplicarHabilidade(tabuleiro, habCone, 4, 4);
    aplicarHabilidade(tabuleiro, habCruz, 7, 7);
    aplicarHabilidade(tabuleiro, habOctaedro, 1, 8);

    // === Exibe o tabuleiro final ===
    printf("\n=== TABULEIRO FINAL ===\n");
    exibirMatriz(tabuleiro);

    return 0;
}