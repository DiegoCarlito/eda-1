/*
1. Nó Raiz ou Nó Pai: Cada nó de uma árvore é a raiz/pai de uma
subárvore;
2. Nó Filho: As raízes das subárvores de um nó P são ditos nós filhos de P;
3. Nós Irmãos: Os filhos de um mesmo nó P são ditos nós irmãos;
4. Grau: A quantidade de subárvores de um nó define seu grau;
5. Nó Folha (ou Terminal): Nós com grau igual a zero;
6. Nível: É relativo ao posicionamento hierárquico de um nó dentro da
árvore (sua distância em relação à raiz). A raiz tem nível zero, seus filhos
tem nível 1, o filho de seus filhos tem nível 2 e assim sucessivamente;
7. Altura: A altura de uma árvore é definida como sendo o seu nível mais
alto.
8. Floresta: Conjunto de zero ou mais árvores disjuntas.
*/

// Árvore Binária
#include <stdio.h>
#include <stdlib.h>

typedef struct nodeB
{
    int info;
    struct nodeB *Esquerda;
    struct nodeB *Direita;
} TNoBin;

/*
ABP que possuem estruturas tal como uma lista
(h=n) são ditas ABP degeneradas.

Tal como em uma lista, o melhor caso é O(1), o
pior caso de uma pesquisa é O(n) (pois h=n) e o
caso médio é O(n/2).

Árvore Balanceada: As alturas das duas
subárvores a partir de cada nó difere no
máximo em uma unidade

*/


/*
instala(TABP *A, TSimbolo s)
	se (A≠Nulo)
		se (s < A->Simbolo)
			instala(A->Esquerda, s)
		senão
			instala(A->Direita, s)
		fimse
	senão
		A = AloqueNo()
		A->Simbolo = s
		A->Esquerda = Nulo
		A->Direita = Nulo
		fimse
fim
*/

TNoBin* aloqueNo(int valor) {
    TNoBin* novoNo = (TNoBin*)malloc(sizeof(TNoBin));
    novoNo->info = valor;
    novoNo->Esquerda = NULL;
    novoNo->Direita = NULL;
    return novoNo;
}

// Função para inserir um símbolo na árvore binária de pesquisa
void instala(TNoBin *A, int valor) {
    if (A != NULL) {
        if (valor < A->info) {
            instala(&(A->Esquerda), valor);
        } else {
            instala(&(A->Direita), valor);
        }
    } else {
        A = aloqueNo(valor);
    }
}

/*
TABP *procura(TABP *A, TSimbolo s)
	se (A≠Nulo)
		se (s = A->Simbolo)
			retorne A;
		senão se (s < A->Simbolo)
			retorne procura(A->Esquerda, s)
		senão
			retorne procura (A->Direita, s)
		fimse
	senão
		retorne Nulo
	fimse
fim
*/

// Pesquisando um símbolo ABP
TNoBin *procura(TNoBin *A, int valor)
{
    if (A != NULL) {
        if (valor == A->info) {
            return A;
        } else if (valor < A->info) {
            return procura(A->Esquerda, valor);
        } else {
            return procura(A->Direita, valor);
        }
    } else {
        return NULL;
    }
}

// Remoção de um Nó em ABP
/*
função encontrarMinimo(raiz):
    enquanto raiz->esquerda ≠ Nulo faça
        raiz = raiz->esquerda
    fim enquanto
    retornar raiz

função remover(raiz, s):
    se raiz for Nulo então
        retornar raiz // Se a árvore estiver vazia, retorna

    se s < raiz->simbolo então
        raiz->esquerda = remover(raiz->esquerda, s) // Procura na subárvore esquerda
    senão se s > raiz->simbolo então
        raiz->direita = remover(raiz->direita, s) // Procura na subárvore direita
    senão // Se o nó a ser removido for encontrado
        se raiz->esquerda for Nulo então
            temp = raiz->direita
            liberar(raiz)
            retornar temp
        senão se raiz->direita for Nulo então
            temp = raiz->esquerda
            liberar(raiz)
            retornar temp
        senão
            temp = encontrarMinimo(raiz->direita) // Encontra o nó mínimo na subárvore direita
            raiz->simbolo = temp->simbolo // Copia o valor do nó mínimo
            raiz->direita = remover(raiz->direita, temp->simbolo) // Remove o nó mínimo
        fim se
    fim se
    retornar raiz
*/
// Função para encontrar o nó mínimo em uma árvore (usada na remoção)
TNoBin* encontrarMinimo(TNoBin* raiz) {
    while (raiz->Esquerda != NULL) {
        raiz = raiz->Direita;
    }
    return raiz;
}

// Função para remover um nó na árvore
TNoBin* remover(TNoBin* raiz, int valor) {
    if (raiz == NULL) {
        return raiz; // Se a árvore estiver vazia, retorna
    }

    if (valor < raiz->info) {
        raiz->Esquerda = remover(raiz->Esquerda, valor); // Procura na subárvore esquerda
    } else if (valor > raiz->info) {
        raiz->Direita = remover(raiz->Direita, valor); // Procura na subárvore direita
    } else { // Se o nó a ser removido for encontrado
        if (raiz->Esquerda == NULL) {
            TNoBin* temp = raiz->Direita;
            free(raiz);
            return temp;
        } else if (raiz->Direita == NULL) {
            TNoBin* temp = raiz->Esquerda;
            free(raiz);
            return temp;
        }

        TNoBin* temp = encontrarMinimo(raiz->Direita); // Encontra o nó mínimo na subárvore direita
        raiz->info = temp->info; // Copia o valor do nó mínimo
        raiz->Direita = remover(raiz->Direita, temp->info); // Remove o nó mínimo
    }
    return raiz;
}
