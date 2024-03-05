#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "arquivos.h"
#include "forca.h"
#define MAX 50


// Funcao de criacao de opcoes para menu
void CriarOpcoes(int tamanho, char opcoes[][MAX]){
    int i;
    printf("====== JOGO DA FORCA ======\n");

    printf("\n");

    //Para cada palavra(opcoes[][MAX]) sera criada uma opcao de menu com printf dada o tamanho do menu(tamanho)
    for(i = 0; i < tamanho; i++){
        printf("[%d] - %s\n", i + 1, opcoes[i]);
    }
}

//Funcao que criara um menu com possibilidade de escolher uma opcao
int CriarMenu(int time, int escolha, int tamanho, char opcoes[][MAX]){

    //Enquanto a opcao escolhida estiver fora do loop
    do{
        //Chamar funcao de criar as opcoes
        CriarOpcoes(tamanho, opcoes);

        printf("\n\nEscolha: ");
        //Salvar a escolha feita pelo usuario
        scanf("%d", &escolha);

        //Limpar o texto antigo
        system("cls");

        //Se a escolha for invalida
        if(escolha > tamanho || escolha < 1){
            //Mensagem de erro
            printf("\n*Escolha uma opcao valida!");
            //Funcao que faz uma pausa por um determinado tempo
            sleep(time);
            //Limpar o texto antigo
            system("cls");
        }
    //Final do loop
    }while(escolha > tamanho || escolha < 1);

    return escolha;
}

//============ DIFICULDADES ============
//Facil
void Facil(FILE* p, char palavra[MAX]){
	LerTexto(p, "palavrasFacil.txt", palavra);
}

//Medio
void Medio(FILE* p, char palavra[MAX]){
	LerTexto(p, "palavrasMedio.txt", palavra);
}

//Dificil
void Dificil(FILE* p, char palavra[MAX]){
    LerTexto(p, "palavrasDificil.txt", palavra);
}

//Extremo
void Extremo(FILE* p, char palavra[MAX]){
    LerTexto(p, "palavrasExtremo.txt", palavra);
}





//Funcao que chama os modos de jogo para uma pessoa
void JogarSozinho(FILE* p, char palavra[MAX]){
    ///Variaveis:
    int escolha;

    printf("----- 'Jogar Sozinho' Selecionado -----");
    sleep(2);
    system("cls");

	//Opcoes do menu
    char opcoes[][MAX] = {"Facil", "Medio", "Dificil","Extremo"}; // palavras
    int tamanho = sizeof(opcoes) / sizeof(opcoes[0]); //tamanho

    //Criar menu de dificuldade
    escolha = CriarMenu(2, escolha, tamanho, opcoes);

    //Seletor de dificuldade
	if(escolha == 1){
    	Facil(p, palavra);
	}
	else if(escolha == 2){
		Medio(p, palavra);
	}
	else if(escolha == 3){
		Dificil(p, palavra);
	}

    else if(escolha == 4){
		Extremo(p, palavra);
	}

}

//Funcao para jogar com amigo
void JogarDupla(char *palavra){

	printf("----- 'Jogar em Dupla' Selecionado -----");
    sleep(2);
    system("cls");

    // Limpar o buffer de entrada antes de ler a palavra
    while (getchar() != '\n');

	//Armazenar palavra do usuario
	checkstr(palavra);
    
	// Remova o caractere de nova linha ('\n') no final da string
    palavra[strcspn(palavra, "\n")] = '\0';

	//*DEBUG*
    //printf("\nPalavra Lida: %s", palavra);
}

//Funcao que controla o modo de jogo selecionado
void SeletorModo(FILE* p, int escolha, char palavra[]){

	//Se a escolha for 1
    if(escolha == 1){
    	//iniciar modo de um jogador
        JogarSozinho(p, palavra);
    }
    //Se a escolha for 2
    if(escolha == 2){

    	//iniciar o modo de dupla
        JogarDupla(palavra);
    }
}
#endif // FUNCOES_H_INCLUDED
