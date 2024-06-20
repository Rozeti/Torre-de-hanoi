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

void jogarHanoi() {
    while (1) {
        printf("Bem-vindo ao Jogo da Torre de Hanoi!\n");
        printf("Regras do jogo:\n");
        printf("1. Apenas um anel pode ser movido por vez.\n");
        printf("2. Um anel so pode ser colocado sobre um anel maior ou em uma torre vazia.\n");
        printf("3. O objetivo e mover todos os aneis da Torre A para a Torre B ou C.\n");
        printf("4. Para encerrar o jogo a qualquer momento, digite 0.\n");
        printf("5. Para reiniciar o jogo a qualquer momento, digite R.\n");

        int num_discos = obterNumDiscos();

        if (num_discos == 0) {
            printf("Jogo encerrado.\n");
            return;
        }

        Torre torres[3];
        for (int i = 0; i < 3; i++) {
            iniciarTorre(&torres[i]);
        }

        for (int i = num_discos; i > 0; i--) {
            push(&torres[0], i);
        }

        char de, para;
        int de_idx, para_idx;

        while (torres[1].topo != num_discos - 1 && torres[2].topo != num_discos - 1) {
            imprimirTorres(torres, num_discos);
            printf("Digite o movimento (ex: AB para mover de A para B, R para reiniciar ou 0 para encerrar): ");
            scanf(" %c", &de);

            if (de == '0') {
                printf("Jogo encerrado.\n");
                return;
            }

            if (de == 'R' || de == 'r') {
                break;
            }

            scanf("%c", &para);

            de = toupper(de);
            para = toupper(para);

            de_idx = de - 'A';
            para_idx = para - 'A';

            if (de_idx < 0 || de_idx > 2 || para_idx < 0 || para_idx > 2) {
                printf("Torre invalida!\n");
                continue;
            }

            if (!movimentoValido(&torres[de_idx], &torres[para_idx])) {
                printf("Movimento invalido!\n");
                continue;
            }

            push(&torres[para_idx], pop(&torres[de_idx]));
        }

        if (torres[1].topo == num_discos - 1 || torres[2].topo == num_discos - 1) {
            imprimirTorres(torres, num_discos);
            printf("Parabens! Voce completou o jogo.\n");
            
            char escolha;
            while (1) {
                printf("Deseja jogar novamente? (S para sim, N para nao): ");
                scanf(" %c", &escolha);
                escolha = toupper(escolha);

                if (escolha == 'N') {
                    printf("Jogo encerrado.\n");
                    return;
                } else if (escolha == 'S') {
                    break;
                } else {
                    printf("Entrada invalida! Por favor, digite S para sim ou N para nao.\n");
                }
            }
        }
    }
}

int main() {
    jogarHanoi();
    return 0;
}
