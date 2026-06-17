#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions_jogo-da-velha.c"

int main(int argc, char *argv[]) 
{
    srand(time(NULL));
    char tabuleiro[3][3];
    char humano = ' ', computador = ' ';
    int modo_auto = 0;

    
    if (argc > 1) 
    {
        humano = argv[1][0];
    } 
    else 
    {
        while (humano != 'X' && humano != 'O' && humano != 'x' && humano != 'o') 
        {
            printf("Escolha seu caractere (X ou O): ");
            scanf(" %c", &humano);
        }
    }
 
    if (humano == 'x') humano = 'X';
    if (humano == 'o') humano = 'O';

    computador = (humano == 'X') ? 'O' : 'X';

    
    if (argc > 2 && strcmp(argv[2], "auto") == 0) 
    {
        modo_auto = 1;
    }

    inicializar_tabuleiro(tabuleiro);
    int turno_humano = 1; 

    while (1) {
        int l, c;

        if (turno_humano) {
            if (modo_auto) {
                jogada_computador(tabuleiro, &l, &c);
            } 
            else 
            {
                printf("Seu turno (%c). Informe a linha (1-3) e coluna (1-3): ", humano);
                while (1) 
                {
                    if (scanf("%d %d", &l, &c) == 2) 
                    {

                        l--; c--; 
                        if (validar_jogada(tabuleiro, l, c)) break;
                    }
                    printf("Jogada inválida! Digite novamente a linha (1-3) e coluna (1-3): ");
                   
                    while (getchar() != '\n');
                }
            }
            tabuleiro[l][c] = humano;
            exibir_tabuleiro(tabuleiro);

            if (verificar_vencedor(tabuleiro, humano))
             {
                printf("O jogador 1 ganhou\n");
                break;
            }
        }
         else
         {
            
            jogada_computador(tabuleiro, &l, &c);
            tabuleiro[l][c] = computador;
            printf("Computador (%c) jogou na linha %d, coluna %d:\n", computador, l + 1, c + 1);
            exibir_tabuleiro(tabuleiro);

            if (verificar_vencedor(tabuleiro, computador)) 
            {
                printf("O jogador 2 ganhou\n");
                break;
            }
        }

        if (tabuleiro_cheio(tabuleiro)) 
        {
            printf("O jogo terminou sem vencedores\n");
            break;
        }

        turno_humano = !turno_humano; 
    }

  
    printf("Criado por [Leonardo Mattoso]\n");
    return 0;
}