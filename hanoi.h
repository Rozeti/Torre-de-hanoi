#ifndef HANOI_H
#define HANOI_H

#define MAX_DISKS 64

typedef struct {
    int discos[MAX_DISKS];
    int topo;
} Torre;

void iniciarTorre(Torre *torre);
void push(Torre *torre, int disco);
int pop(Torre *torre);
void imprimirDisco(int disco, int max_discos);
void imprimirTorres(Torre torres[], int num_discos);
int movimentoValido(Torre *de, Torre *para);
int obterNumDiscos();
void jogarHanoi();

#endif 
