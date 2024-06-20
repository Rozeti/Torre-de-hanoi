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
