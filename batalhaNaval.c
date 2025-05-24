#include <stdio.h>

void sobreporHabilidade(int tab[10][10], int hab[][5], int linhas, int colunas, int origemLinha, int origemColuna);

int main() {
    int tabuleiro[10][10] = {0};

    // Exemplo de navios
    tabuleiro[3][3] = 3; // N
    tabuleiro[3][4] = 3;
    tabuleiro[3][5] = 3;

    // Criar matriz do cone (3x5)
    int cone[3][5];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cone[i][j] = (j >= 2 - i && j <= 2 + i) ? 1 : 0;
        }
    }

    // Criar matriz da cruz (5x5)
    int cruz[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cruz[i][j] = (i == 2 || j == 2) ? 2 : 0;
        }
    }

    // Criar matriz do octaedro (5x5)
    int octaedro[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int distLinha = i > 2 ? i - 2 : 2 - i;
            int distCol = j > 2 ? j - 2 : 2 - j;
            octaedro[i][j] = (distLinha + distCol <= 2) ? 5 : 0;
        }
    }

    // Sobrepor as habilidades
    sobreporHabilidade(tabuleiro, cone, 3, 5, 0, 2);      // topo do tabuleiro, col 2
    sobreporHabilidade(tabuleiro, cruz, 5, 5, 5, 5);      // centro do tabuleiro (linha 5, col 5)
    sobreporHabilidade(tabuleiro, octaedro, 5, 5, 8, 7);  // perto do canto inferior direito

    // Imprimir tabuleiro
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < 10; i++) {
        printf("%c| ", 'A' + i);
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0) printf("0 ");
            else if (tabuleiro[i][j] == 3) printf("N ");
            else printf("%d ", tabuleiro[i][j]); // imprime 1,2,5 para áreas de habilidade
        }
        printf("\n");
    }

    return 0;
}

void sobreporHabilidade(int tab[10][10], int hab[][5], int linhas, int colunas, int origemLinha, int origemColuna) {
    int meioLinha = linhas / 2;
    int meioColuna = colunas / 2;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int linhaTab = origemLinha - meioLinha + i;
            int colTab = origemColuna - meioColuna + j;

            if (linhaTab >= 0 && linhaTab < 10 && colTab >= 0 && colTab < 10) {
                if (hab[i][j] != 0 && tab[linhaTab][colTab] != 3) {
                    tab[linhaTab][colTab] = hab[i][j];
                }
            }
        }
    }
}
