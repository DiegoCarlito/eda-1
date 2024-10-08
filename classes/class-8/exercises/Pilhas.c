#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
- A Pilha é uma estrutura de dados com regras de
acesso: O último elemento armazenado é o
primeiro a ser removido;
- LIFO (Last In, First Out);
*/


// Definição do tipo de dado a ser armazenado na pilha (pode ser alterado conforme necessidade)
typedef struct {
    int dado; // Exemplo de um elemento que armazena um número inteiro
} TElemento;

// Definição da estrutura da pilha
#define TAMANHO_MAXIMO 100 // Tamanho máximo da pilha (pode ser alterado conforme necessidade)

typedef struct {
    TElemento elementos[TAMANHO_MAXIMO];
    int topo; // Índice que indica o topo da pilha
} TPilha;

// Função para esvaziar a pilha
void Esvazia(TPilha *Pilha) {
    Pilha->topo = -1; // Reinicializa o topo da pilha para indicar que está vazia
}

// Função para verificar se a pilha está vazia
bool Vazia(TPilha *Pilha) {
    return (Pilha->topo == -1); // Retorna verdadeiro se o topo for -1 (pilha vazia)
}

// Função para empilhar um elemento na pilha
bool Empilha(TPilha *Pilha, TElemento *Elemento) {
    if (Pilha->topo == TAMANHO_MAXIMO - 1) {
        printf("Erro: Pilha cheia\n");
        return false; // Se a pilha estiver cheia, não é possível empilhar mais elementos
    }

    Pilha->topo++; // Incrementa o topo
    Pilha->elementos[Pilha->topo] = *Elemento; // Armazena o elemento no topo da pilha
    return true;
}

// Função para desempilhar um elemento da pilha
TElemento *Desempilha(TPilha *Pilha) {
    if (Vazia(Pilha)) {
        printf("Erro: Pilha vazia\n");
        return NULL; // Se a pilha estiver vazia, não é possível desempilhar
    }

    TElemento *elementoDesempilhado = &(Pilha->elementos[Pilha->topo]); // Guarda o elemento do topo
    Pilha->topo--; // Decrementa o topo para remover o elemento
    return elementoDesempilhado;
}

// Função para consultar o elemento do topo da pilha sem removê-lo
TElemento *Consulta(TPilha *Pilha) {
    if (Vazia(Pilha)) {
        printf("Erro: Pilha vazia\n");
        return NULL; // Se a pilha estiver vazia, não é possível consultar
    }

    return &(Pilha->elementos[Pilha->topo]); // Retorna o elemento do topo da pilha
}

// Função principal para testar as operações da pilha
int main() {
    TPilha minhaPilha;
    minhaPilha.topo = -1; // Inicializa a pilha vazia

    TElemento elemento1 = {10};
    TElemento elemento2 = {20};
    TElemento *elementoTopo;

    Empilha(&minhaPilha, &elemento1);
    Empilha(&minhaPilha, &elemento2);

    elementoTopo = Consulta(&minhaPilha);
    if (elementoTopo != NULL) {
        printf("Elemento do topo da pilha: %d\n", elementoTopo->dado);
    }

    TElemento *elementoDesempilhado = Desempilha(&minhaPilha);
    if (elementoDesempilhado != NULL) {
        printf("Elemento desempilhado: %d\n", elementoDesempilhado->dado);
    }

    elementoTopo = Consulta(&minhaPilha);
    if (elementoTopo != NULL) {
        printf("Novo elemento do topo da pilha: %d\n", elementoTopo->dado);
    }

    return 0;
}
