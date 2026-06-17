
#include <stdio.h>
#include <stdlib.h>

void inicializar_tabuleiro(char tab[3][3]) 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            tab[i][j] = ' ';
        }
    }
}


void exibir_tabuleiro(char tab[3][3]) 
{
    for (int i = 0; i < 3; i++) 
    {
        printf("| %c | %c | %c |\n", tab[i][0], tab[i][1], tab[i][2]);
    }
    printf("\n");
}

int validar_jogada(char tab[3][3], int linha, int coluna) 
{
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) 
    {
        return 0;
    }
    if (tab[linha][coluna] != ' ') 
    {
        return 0;
    }
    return 1;
}


int verificar_vencedor(char tab[3][3], char jogador) 
{
    
    for (int i = 0; i < 3; i++) 
    {
        if (tab[i][0] == jogador && tab[i][1] == jogador && tab[i][2] == jogador) return 1;
        if (tab[0][i] == jogador && tab[1][i] == jogador && tab[2][i] == jogador) return 1;
    }
    
    if (tab[0][0] == jogador && tab[1][1] == jogador && tab[2][2] == jogador) return 1;
    if (tab[0][2] == jogador && tab[1][1] == jogador && tab[2][0] == jogador) return 1;

    return 0;
}

int tabuleiro_cheio(char tab[3][3])
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (tab[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void jogada_computador(char tab[3][3], int *linha, int *coluna) 
{
    do 
    {
        *linha = rand() % 3;
        *coluna = rand() % 3;
    } 
    while (!validar_jogada(tab, *linha, *coluna));
}