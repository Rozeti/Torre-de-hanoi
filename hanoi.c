#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "hanoi.h"

void iniciarTorre(Torre *torre) {
    torre->topo = -1;
}

void push(Torre *torre, int disco) {
    if (torre->topo < MAX_DISKS - 1) {
        torre->discos[++torre->topo] = disco;
    }
}

int pop(Torre *torre) {
    if (torre->topo >= 0) {
        return torre->discos[torre->topo--];
    }
    return -1;
}

void imprimirDisco(int disco, int max_discos) {
    int largura = max_discos * 2 - 1;
    int num_hashes = disco * 2 - 1;
    int num_espacos = (largura - num_hashes) / 2;
    
    for (int i = 0; i < num_espacos; i++) {
        printf(" ");
    }
    for (int i = 0; i < num_hashes; i++) {
        printf("#");
    }
    for (int i = 0; i < num_espacos; i++) {
        printf(" ");
    }
}

void imprimirTorres(Torre torres[], int num_discos) {
    int largura = num_discos * 2 - 1;

    for (int i = num_discos - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (i <= torres[j].topo) {
                imprimirDisco(torres[j].discos[i], num_discos);
            } else {
                for (int k = 0; k < largura; k++) {
                    printf(" ");
                }
            }
            printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < largura; j++) {
            printf("-");
        }
        printf(" ");
    }
    printf("\n");

    printf("  A  ");
    for (int i = 0; i < largura - 2; i++) printf(" ");
    printf("  B  ");
    for (int i = 0; i < largura - 2; i++) printf(" ");
    printf("  C  \n\n");
}

int movimentoValido(Torre *de, Torre *para) {
    if (de->topo == -1) return 0;
    if (para->topo == -1) return 1;
    return de->discos[de->topo] < para->discos[para->topo];
}

int obterNumDiscos() {
    char entrada[10];
    int num_discos;

    while (1) {
        printf("\nDigite o numero de aneis (ou 0 para encerrar): ");
        scanf("%s", entrada);

        int is_numeric = 1;
        for (int i = 0; i < strlen(entrada); i++) {
            if (!isdigit(entrada[i])) {
                is_numeric = 0;
                break;
            }
        }

        if (is_numeric) {
            num_discos = atoi(entrada);
            if (num_discos >= 0 && num_discos <= MAX_DISKS) {
                return num_discos;
            } else {
                printf("Numero de aneis invalido! Deve estar entre 0 e %d.\n", MAX_DISKS);
            }
        } else {
            printf("Entrada invalida! Por favor, insira um numero.\n");
        }
    }
}
