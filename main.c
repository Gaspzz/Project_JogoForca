#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "desenho.h"
#include "menu.h"
#include "arquivos.h"
#include "forca.h"

//============ ESTRUTURAS ============
//Estrutura capaz de armazenar os dados dos jogadores
struct jogadores{
	char nome[MAX];
	int pontos;
};

//============ FUNCAO PRINCIPAL ============
int main() {

	//============ TESTE FUNCAO MENU ============
	///Variaveis:
    //Menu:
    int modoDeJogo = 0; //escolha do modo de jogo
    char opcoesMenu[][MAX] = {"Jogar Sozinho", "Jogar em Dupla", "Sair"}; //palavras do menu principal
    int tamanhoMenu = sizeof(opcoesMenu) / sizeof(opcoesMenu[0]); //tamanho do menu principal
    FILE* arquivo; //ponteiro do arquivo
	char palavra[MAX]; //palavra que sera usada no jogo

    //*Menu Principal*
    modoDeJogo = CriarMenu(2, modoDeJogo, tamanhoMenu, opcoesMenu);

    //*Seletor de modo*
    SeletorModo(arquivo, modoDeJogo, palavra);

    //teste estrutura
    struct jogadores player1;

	//Rodar logica do jogo
    player1.pontos = Forca(palavra);
    
    //Salvar dados
    SalvarPlayer(arquivo, player1.nome, player1.pontos, "Players.txt");

	return 0;
}
