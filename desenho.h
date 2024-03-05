#ifndef DESENHO_H_INCLUDED
#define DESENHO_H_INCLUDED

void desenharForca(int tentativasErradas) {
    printf("------\n");
    printf("|    |\n");

    if (tentativasErradas >= 1) {
        printf("|    O\n");
    } else {
        printf("|\n");
    }

    if (tentativasErradas == 2) {
        printf("|    |\n");
    } else if (tentativasErradas == 3) {
        printf("|   /|\n");
    } else if (tentativasErradas >= 4) {
        printf("|   /|\\\n");
    } else {
        printf("|\n");
    }

    if (tentativasErradas == 5) {
        printf("|   /\n");
    } else if (tentativasErradas >= 6) {
        printf("|   / \\\n");
    } else {
        printf("|\n");
    }

    printf("|\n");
    printf("--------\n");
}
#endif
