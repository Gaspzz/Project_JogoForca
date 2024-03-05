#ifndef FORCA_H_INCLUDED
#define FORCA_H_INCLUDED
#include "desenho.h"
#include "arquivos.h"
#include <ctype.h>

int dicasDisponiveis = 1;
char dica[MAX];
int letrasReveladas[MAX];

void inicializarLetrasReveladas() {
    for (int i = 0; i < MAX; i++) {
        letrasReveladas[i] = 0;
    }
}

void obterDica(char palavra[MAX], char certas[MAX]) {
    if (dicasDisponiveis > 0) {
        for (int i = 0; i < strlen(palavra); i++) {
            if (!letrasReveladas[i] && isalpha(palavra[i])) {
                certas[i] = palavra[i];
                letrasReveladas[i] = 1;
                dicasDisponiveis--;
                break;
            }
        }

        printf("Dica: %s\n", certas);
    } else {
        printf("Você já usou todas as dicas disponíveis.\n");
    }
}

void checkstr(char *wor) {
    int i, a, l, k;
    k = 1;
    while (k == 1) {
        printf("\nDigite a palavra a ser adivinhada:");
        scanf("%s", wor);
        l = strlen(wor);
        k = 1;
        i = 0;
        for (i = 0; i < l; i++) {
            a = isalpha(*(wor + i));
            if (a == 0) {
                printf("Input invalido, digite a palavra novamente.\n");
                break;
            } else if (a == 1) {
                *(wor + i) = *(wor + i) + 32;
            }
            if (i == l - 1) {
                k = 0;
            }
        }
    }
}

void checkchar(char *wor) {
    int i, a, l, k;
    k = 1;
    while (k == 1) {
        printf("Digite a letra:");
        fgets(wor, 2, stdin);

        system("cls");

        l = strlen(wor);
        k = 1;
        i = 0;
        a = isalpha(*(wor));
        if (l != 1 || a == 0) {
            printf("Input invalido, digite a letra novamente.");
        } else {
            k = 0;
            if (a == 1) {
                *wor = *wor + 32;
            }
        }
    }
}

int Forca(char *word) {
    char guess[50], erradas[7], certas[50], wordcop[50], chara[50];
    char letter;
    char alfa[] = "abcdefghijklmnopqrstuvwxyz";
    int j, k, m, let, len, cont_errada, cont_cert, x, y;
    int modo;

    int pontos = 1000;

    len = strlen(word);

    strcpy(wordcop, word);

    strcpy(certas, word);

    cont_cert = 0;
    cont_errada = 0;

    for (k = 0; k < len; k++) {
        certas[k] = '_';
    }

    desenharForca(0);

    j = 0;
    y = 0;

    inicializarLetrasReveladas();

    while (cont_errada < 7) {
        while (getchar() != '\n');

        printf("\nEscolha o modo:\n 1-Chute direto\n 2-Letra por letra\n 3-Obter Dica\n Modo:");
        scanf("%d", &modo);

        while (getchar() != '\n');

        if (modo == 1) {
            checkstr(guess);

            if (strcmp(wordcop, guess) == 0) {
                printf("\nVoce venceu!");
                pontos *= (len - (cont_cert + 1));
            } else {
                printf("\nVoce perdeu... a palavra era %s", wordcop);
                pontos = 0;
            }
            return 0;
        } else if (modo == 2) {
            checkchar(chara);
            letter = chara[0];
            let = letter - 97;
            x = 0;
            if (letter != alfa[let]) {
                printf("\nLetra ja digitada.\n");
            } else {
                alfa[let] = '0';
                for (j = 0; j < len; j++) {
                    if (letter == word[j]) {
                        word[j] = '0';
                        certas[j] = letter;
                        x += 1;
                    }
                    if (j == len - 1) {
                        if (x == 0) {
                            erradas[cont_errada] = letter;
                            printf("\nLetra errada\n");
                            cont_errada++;
                            pontos -= 100;
                        } else {
                            cont_cert += x;
                            printf("\nLetra certa\n");
                            pontos += 500;
                        }
                    }
                    if (cont_cert == len) {
                        pontos *= 2;
                        printf("\nVoce venceu!");
                        printf("\tPontos: %d", pontos);
                        return pontos;
                    } else if (cont_errada == 7) {
                        printf("\nVoce perdeu... A palavra era: %s", wordcop);
                        printf("\tPontos: %d", pontos);
                        return pontos;
                    }
                }
                printf("\n");
                desenharForca(cont_errada);
                printf("\n");
                printf("Ja adivinhado:");
                for (y = 0; y < len; y++) {
                    printf("%c", certas[y]);
                }
                printf(" Erradas:");
                for (y = 0; y < cont_errada; y++) {
                    printf("%c ", erradas[y]);
                }
                printf("\n");
            }
        } else if (modo == 3) {
            obterDica(word, certas);
        } else {
            printf("Modo invalido, digite novamente.\n");
        }
    }
}

#endif