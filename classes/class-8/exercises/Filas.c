#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição do tipo de dado a ser armazenado na fila (pode ser alterado conforme necessidade)
typedef struct {
    int dado; // Exemplo de um elemento que armazena um número inteiro
} TElemento;

// Definição da estrutura da fila (implementada com um vetor)
#define TAMANHO_MAXIMO 100 // Tamanho máximo da fila (pode ser alterado conforme necessidade)

typedef struct {
    TElemento elementos[TAMANHO_MAXIMO];
    int inicio; // Índice que indica o início da fila
    int fim; // Índice que indica o fim da fila
    int quantidade; // Variável para controlar a quantidade de elementos na fila
} TFila;

// Função para esvaziar a fila
void Esvazia(TFila *Fila) {
    Fila->inicio = 0; // Reinicializa o início da fila
    Fila->fim = -1; // Reinicializa o fim da fila
    Fila->quantidade = 0; // Reinicializa a quantidade de elementos na fila
}

// Função para verificar se a fila está vazia
bool Vazia(TFila *Fila) {
    return (Fila->quantidade == 0); // Retorna verdadeiro se a quantidade for zero (fila vazia)
}

// Função para verificar se a fila está cheia (para implementação com vetores)
bool Cheia(TFila *Fila) {
    return (Fila->quantidade == TAMANHO_MAXIMO); // Retorna verdadeiro se a quantidade atingir o máximo
}

// Função para enfileirar um elemento no final da fila
bool Enfileira(TFila *Fila, TElemento *Elemento) {
    if (Cheia(Fila)) {
        printf("Erro: Fila cheia\n");
        return false; // Se a fila estiver cheia, não é possível enfileirar mais elementos
    }

    Fila->fim = (Fila->fim + 1) % TAMANHO_MAXIMO; // Calcula o novo índice do fim
    Fila->elementos[Fila->fim] = *Elemento; // Armazena o elemento no fim da fila
    Fila->quantidade++; // Incrementa a quantidade de elementos na fila
    return true;
}

// Função para desenfileirar um elemento do início da fila
TElemento *Desenfileira(TFila *Fila) {
    if (Vazia(Fila)) {
        printf("Erro: Fila vazia\n");
        return NULL; // Se a fila estiver vazia, não é possível desenfileirar
    }

    TElemento *elementoDesenfileirado = &(Fila->elementos[Fila->inicio]); // Guarda o elemento do início
    Fila->inicio = (Fila->inicio + 1) % TAMANHO_MAXIMO; // Calcula o novo índice do início
    Fila->quantidade--; // Decrementa a quantidade de elementos na fila
    return elementoDesenfileirado;
}

// Função para consultar o elemento do início da fila sem removê-lo
TElemento *Consulta(TFila *Fila) {
    if (Vazia(Fila)) {
        printf("Erro: Fila vazia\n");
        return NULL; // Se a fila estiver vazia, não é possível consultar
    }

    return &(Fila->elementos[Fila->inicio]); // Retorna o elemento do início da fila
}

// Função principal para testar as operações da fila
int main() {
    TFila minhaFila;
    Esvazia(&minhaFila); // Inicializa a fila vazia

    TElemento elemento1 = {10};
    TElemento elemento2 = {20};
    TElemento *elementoInicio;

    Enfileira(&minhaFila, &elemento1);
    Enfileira(&minhaFila, &elemento2);

    elementoInicio = Consulta(&minhaFila);
    if (elementoInicio != NULL) {
        printf("Elemento do inicio da fila: %d\n", elementoInicio->dado);
    }

    TElemento *elementoDesenfileirado = Desenfileira(&minhaFila);
    if (elementoDesenfileirado != NULL) {
        printf("Elemento desenfileirado: %d\n", elementoDesenfileirado->dado);
    }

    elementoInicio = Consulta(&minhaFila);
    if (elementoInicio != NULL) {
        printf("Novo elemento do inicio da fila: %d\n", elementoInicio->dado);
    }

    return 0;
}