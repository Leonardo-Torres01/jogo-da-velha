#include <stdio.h>
#include <assert.h>
#include "functions_jogo-da-velha.c"

void rodar_testes() 
{
    char t[3][3];

   
    inicializar_tabuleiro(t);
    for(int i=0; i<3; i++) 
    {
        for(int j=0; j<3; j++) 
        {
            assert(t[i][j] == ' ');
        }
    }
    printf("Teste Inicialização: PASSOU\n");

    
    assert(validar_jogada(t, 0, 0) == 1);
    assert(validar_jogada(t, 3, 0) == 0); 
    t[0][0] = 'X';
    assert(validar_jogada(t, 0, 0) == 0); 
    printf("Teste Validação: PASSOU\n");

  
    inicializar_tabuleiro(t);
    t[1][0] = 'X'; t[1][1] = 'X'; t[1][2] = 'X';
    assert(verificar_vencedor(t, 'X') == 1);
    assert(verificar_vencedor(t, 'O') == 0);
    printf("Teste Vencedor Linha: PASSOU\n");

    
    inicializar_tabuleiro(t);
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    t[i][j] = 'X';
    assert(tabuleiro_cheio(t) == 1);
    printf("Teste Tabuleiro Cheio: PASSOU\n");
}

int main() {
    printf("Iniciando testes automatizados...\n");
    rodar_testes();
    printf("Todos os testes passaram com sucesso!\n");
    
   
    printf("Criado por [Leonardo Mattoso ]\n");
    return 0;
}