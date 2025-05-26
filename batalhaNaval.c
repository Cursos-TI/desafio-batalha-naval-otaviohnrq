#include <stdio.h>

// Definindo o tamanho do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10, preenchido inicialmente com 0 (representando água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Definição dos navios (valores simbólicos, pois apenas o valor 3 será usado no tabuleiro)
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3};  // Navio horizontal com tamanho 3
    int navio_vertical[TAM_NAVIO] = {3, 3, 3};    // Navio vertical com tamanho 3

    // Coordenadas iniciais para o navio horizontal (linha e coluna)
    int linha_h = 2;
    int coluna_h = 4;

    // Coordenadas iniciais para o navio vertical (linha e coluna)
    int linha_v = 5;
    int coluna_v = 7;

    // Validação para garantir que o navio horizontal cabe dentro do tabuleiro
    if (coluna_h + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Validação para garantir que o navio vertical cabe dentro do tabuleiro
    if (linha_v + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Verificação de sobreposição antes de posicionar o navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_h][coluna_h + i] != 0) {
            printf("Erro: sobreposição detectada ao posicionar o navio horizontal.\n");
            return 1;
        }
    }

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // Verificação de sobreposição antes de posicionar o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_v + i][coluna_v] != 0) {
            printf("Erro: sobreposição detectada ao posicionar o navio vertical.\n");
            return 1;
        }
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Exibição do tabuleiro com os navios posicionados
    printf("Tabuleiro:\n\n");

    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);  // Imprime cada posição da matriz
        }
        printf("\n");  // Quebra de linha após cada linha do tabuleiro
    }

    return 0;  // Indica que o programa foi executado com sucesso
}