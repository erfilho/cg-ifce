#ifndef _ABC_H
#define _ABC_H

typedef struct {
    int x, y;
} tPonto;

typedef struct no {
    tPonto ponto;
    struct no* prox;
} tVertice;

typedef struct {
    tVertice* head;
    tVertice* tail;
    int qtd_no;
} tPoligono;

tVertice* cria_vertice(tPonto ponto);
tPoligono* 

#endif