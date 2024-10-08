#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *ant;
    int num;
    struct node *prox;
} TNo;

typedef struct Duplamente_encadeadas {
    TNo *Primeiro;
    int qtde;
    TNo *Ultimo;
} TLista;


int vazia (TNo *lista){
    if (lista == NULL) {
        return -1;
    } else {
        return 0;
    }
}

TNo *incluiCabeca(TNo *lista, int valor) {
    TNo *pNovoNo;
    pNovoNo = (TNo*)malloc(sizeof(TNo));
    pNovoNo->num = valor;
    pNovoNo->ant = NULL;
    pNovoNo->prox = lista;
    lista->ant = pNovoNo;
    lista = pNovoNo;
    return lista;
}

TNo *incluiCauda(TNo *lista, int valor) {
    TNo *pNovoNo, *pAux;
    pNovoNo = (TNo*)malloc(sizeof(TNo));
    pNovoNo->num = valor;
    pNovoNo->prox = NULL;
    pAux = lista;
    while (pAux->prox != NULL) {
        pAux = pAux->prox;
    }
    pAux->prox = pNovoNo;
    pNovoNo->ant = pAux;
    return lista;
}

TNo *incluiDepois(TNo *lista, int chave, int valor) {
    TNo *pNovoNo, *pAux;
    pNovoNo = (TNo*)malloc(sizeof(TNo));
    pNovoNo->num = valor;
    pAux = lista;
    while (pAux->num != chave) {
        pAux = pAux->prox;
    }
    pNovoNo->prox = pAux->prox;
    pNovoNo->ant = pAux;
    pAux->prox = pNovoNo;
    pNovoNo->prox->ant = pNovoNo;
    return lista;
}

TNo *excluiCabeca(TNo *lista) {
    lista = lista->prox;
    free(lista->ant);
    lista->ant = NULL;
    return lista;
}

TNo *excluiCauda(TNo *lista) {
    TNo *pAux;
    pAux = lista;
    while (pAux->prox->prox != NULL) {
        pAux = pAux->prox;
    }
    free(pAux->prox);
    pAux->prox = NULL;
    return lista;
}

TNo *excluiChave(TNo *lista, int chave) {
    TNo *pAux;
    pAux = lista;
    while (pAux->num != chave) {
        pAux = pAux->prox;
    }
    pAux->ant->prox = pAux->prox;
    pAux->prox->ant = pAux->ant;
    free(pAux);
    return lista;
}