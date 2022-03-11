#include "abc.h"
#include <stdlib.h>


tVertice* cria_vertice(tPonto ponto) {
    tVertice* novo_vertice = (tVertice*)malloc(sizeof(tVertice));
    novo_vertice->ponto = ponto;
    novo_vertice->prox = NULL;
    return novo_vertice;
}

tPoligono* cria_poligono(){
    tPoligono novo_poligono = (tPoligono*)malloc(sizeof(tPoligono));
    novo_poligono->head = NULL;
    novo_poligono->tail = NULL;
    novo_poligono->qtd_no = 0;
    return novo_poligono;
}

int del_vertice(tVertice vertice){
    free(vertice);
    return 1;
}

int del_poligono(tPoligono poligono){
    tVertice* temp = (tVertice*)malloc(sizeof(tPoligono));
    temp = 
    free(poligono);
    return 1;
}