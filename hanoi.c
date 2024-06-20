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
