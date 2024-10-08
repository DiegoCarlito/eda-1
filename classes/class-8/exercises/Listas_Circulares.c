#include <stdio.h>
#include <stdlib.h>

/*
Uma lista circular é uma lista onde o campo próximo
do último elemento aponta para o primeiro
elemento da lista e o campo anterior do primeiro
elemento aponta para o último, quando for o caso
(duplamente encadeada);
*/

// Encadeada circular
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Estrutura da lista encadeada circular
typedef struct LinkedList {
    Node *head; // Ponteiro para o primeiro nó da lista
} LinkedList;

// Duplamente encadeada circular
typedef struct DNode {
    int data;
    struct DNode *prev; // Ponteiro para o nó anterior
    struct DNode *next; // Ponteiro para o próximo nó
} DNode;

// Estrutura da lista duplamente encadeada circular
typedef struct DLinkedList {
    DNode *head; // Ponteiro para o primeiro nó da lista
} DLinkedList;
