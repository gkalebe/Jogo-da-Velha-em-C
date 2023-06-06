#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt-br"); 
    setlocale(LC_CTYPE, "UTF-8");

    int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;
    char jogo[3][3];
    int vitorias_jogador1 = 0;
    int vitorias_jogador2 = 0;

    do {
        jogador = 1;
        ganhou = 0;
        jogadas = 0;

        for (l = 0; l < 3; l++) {
            for (c = 0; c < 3; c++) {
                jogo[l][c] = ' ';
            }
        }

        do {
            printf("\n\n\t 0   1   2\n\n");
            for (l = 0; l < 3; l++) {
                for (c = 0; c < 3; c++) {
                    if (c == 0)
                        printf("\t");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2)
                        printf("|");
                    if (c == 2)
                        printf("  %d", l);
                }
                if (l < 2)
                    printf("\n\t-----------");
                printf("\n");
            }

            do {
                printf("\nJOGADOR 1 = 0\nJOGADOR 2 = X\n");
                printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar (0 a 2): ", jogador);
                scanf("%d%d", &linha, &coluna);

               
                if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ') {
                    printf("Entrada inválida. Tente novamente.\n");
                    continue;
                }

                
                if ((jogador == 1 && jogo[linha][coluna] == 'X') || (jogador == 2 && jogo[linha][coluna] == '0')) {
                    printf("Essa posição já está ocupada. Tente novamente.\n");
                    continue;
                }

                break;
            } while (1);

            if (jogador == 1) {
                jogo[linha][coluna] = '0';
                jogador++;
            } else {
                jogo[linha][coluna] = 'X';
                jogador = 1;
            }
            jogadas++;

            if ((jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0') ||
                (jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0') ||
                (jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0') ||
                (jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0') ||
                (jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0') ||
                (jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0') ||
                (jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0') ||
                (jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0')) {
                printf("\nParabéns! O jogador 1 venceu!\n");
                vitorias_jogador1++;
                ganhou = 1;
            } else if ((jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') ||
                       (jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') ||
                       (jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X') ||
                       (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') ||
                       (jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') ||
                       (jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X') ||
                       (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') ||
                       (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X')) {
                printf("\nParabéns! O jogador 2 venceu!\n");
                vitorias_jogador2++;
                ganhou = 1;
            }

           
            if (jogadas == 9 && ganhou == 0) {
                printf("\nDeu velha!\n");
                break;
            }

        } while (ganhou == 0 && jogadas < 9);

        printf("\n\n\t 0   1   2\n\n");
        for (l = 0; l < 3; l++) {
            for (c = 0; c < 3; c++) {
                if (c == 0)
                    printf("\t");
                printf(" %c ", jogo[l][c]);
                if (c < 2)
                    printf("|");
                if (c == 2)
                    printf("  %d", l);
            }
            if (l < 2)
                printf("\n\t-----------");
            printf("\n");
        }

        printf("\nPlacar:\n");
        printf("Jogador 1: %d vitórias\n", vitorias_jogador1);
        printf("Jogador 2: %d vitórias\n", vitorias_jogador2);

        printf("\nDigite 1 para jogar novamente ou 0 para encerrar o programa: ");
        scanf("%d", &opcao);

        if (opcao != 1) {
            break;
        }

    } while (1);

    return 0;
}

