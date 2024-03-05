#ifndef ARQUIVOS_H_INCLUDED
#define ARQUIVOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define MAX 50

//========== Manipular um Arquivo ==========
FILE* Manipular(FILE* p, char nome[MAX], char modo[2]){
	
	//abrindo o arquivo
	p = fopen(nome, modo);
	
	//Se o ponteiro for nulo
	if(p == NULL){
		//*Mensagem de erro DEBUG*
		//printf("Erro na abertura do arquivo.\n");
		exit(1);
	}
	//Caso nao for nulo
	else{
		//*DEBUG*
		//printf("Arquivo aberto com sucesso.\n");
	}
	
	//Retornar ponteiro
	return p;	
}

//========== Fechar um Arquivo ==========
void Fechar(FILE* p){
	
	//Verificacao
	if(p != NULL){
		//*DEBUG*
		//printf("\nFechado com sucesso.");
	}
	else{
		//*DEBUG*
		//printf("\nErro ao fechar arquivo.");
	}
	
	fclose(p);
}

//========== Escrever Texto em um Arquivo ==========
void EscreverTexto(FILE* p, char texto[100], int pontos, char nome[MAX]){
	///Variaveis:	
	//contador
	int i;
	
	// Verificar se o arquivo já existe antes de abrir
    if(access(nome, F_OK) != -1) {
    		//Se existir   		
    		//*DEBUG*
            //printf("O arquivo ja existe. Adicionando conteudo...\n");
            //Adicionar as novas informacoes
            p = Manipular(p, nome, "a");           
        } else {
        	//Caso nao exista
        	//*DEBUG*
            //printf("O arquivo nao existe. Criando um novo...\n");
            //Criar um arquivo novo
            p = Manipular(p, nome, "w");            
    }
	
	//Se o ponteiro for nulo
	if(p == NULL){
		//*DEBUG*
		//printf("Erro na abertura do arquivo.\n");
	}
	
	//*Gravando no arquivo*
	for(i = 0; i < strlen(texto); i++){
		fputc(texto[i], p);
	}
	
	//Caso exista pontos adicionar eles ao arquivo
	if(pontos > 0){	
		//*Gravando os pontos*
		fprintf(p, "\t%d\n", pontos);
	}
	//Se nao existir pontos
	else{
		//Pular linha
		fputc('\n', p);
	}
	
	//*Fechando o arquivo*
	Fechar(p);	
}

//========== Ler Texto em um Arquivo ==========
void LerTexto(FILE* p, char nome[MAX], char palavra[MAX]){
	///Variaveis:
	//caractere que sera exibido
	char c;
	//contador
	int i, numeroLinhas = 0;	
	//salva a linha aleatoria da palavra
	int linhaEscolhida;
	//==========================================
	
	//*Abrindo o arquivo*
	p = Manipular(p, nome, "r");
	
	//*Contando o numero de linhas*
	while (fgets(palavra, MAX, p) != NULL) {
        numeroLinhas++;
    }
    
    // Fecha e reabre o arquivo para voltar ao início
    Fechar(p);
    p = Manipular(p, nome, "r");
    
    // Gera um número aleatório entre 1 e o número total de linhas
    srand(time(NULL));
    linhaEscolhida = rand() % numeroLinhas + 1;
	
	//*Lendo a palavra*
	for (i = 1; i <= linhaEscolhida; i++) 
	{
        fgets(palavra, MAX, p);
    }
    
    // Remove a quebra de linha da palavra, se houver
    palavra[strcspn(palavra, "\n")] = '\0';

    //*DEBUG*
    //printf("Palavra aleatoria: %s\n", palavra);   
	
	//*Fechando o arquivo
	Fechar(p);	
	
}

//========== Salvar jogador em um Arquivo ==========
void SalvarPlayer(FILE* p, char nomeJogador[MAX], int pontos, char nomeArquivo[MAX]){
	
	// Limpar o buffer de entrada antes de ler a palavra
    while (getchar() != '\n');
	
	//Recebendo nome do jogador
	printf("\nDigite seu nome: ");
	fgets(nomeJogador, MAX, stdin);
	
	// Remova o caractere de nova linha ('\n') no final da string
    nomeJogador[strcspn(nomeJogador, "\n")] = '\0';
	
	//*Gravando no arquivo*
	EscreverTexto(p, nomeJogador, pontos, nomeArquivo);	
		
}

#endif
