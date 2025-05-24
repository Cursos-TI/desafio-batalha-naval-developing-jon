#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    // 1. Inicializar tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Criar dois navios com tamanho 3
    int navioH[3] = {3, 3, 3}; // Navio horizontal
    int navioV[3] = {3, 3, 3}; // Navio vertical

    // 3. Posicionar o navio horizontal (linha 2, coluna 1)
    int linhaH = 2;
    int colunaH = 1;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioH[i];
    }

    // 4. Posicionar o navio vertical (linha 5, coluna 7)
    int linhaV = 5;
    int colunaV = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }

    // 5. Imprimir cabeçalho com números (colunas)
    printf("    ");
    for (int col = 1; col <= 10; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    // 6. Imprimir tabuleiro com letras (linhas)
    for (int i = 0; i < 10; i++) {
        printf(" %c |", 'A' + i); // Linha A até J

        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

