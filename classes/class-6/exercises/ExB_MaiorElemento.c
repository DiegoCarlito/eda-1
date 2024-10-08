#include <stdio.h>
#include <stdlib.h>
#include "./lab/VetoresC.h"

int MaiorElemento(int *a, int qtde) {
    if (qtde <= 0) {
        return a[0];
    } 

    int maior_anterior = MaiorElemento(a, qtde-1);
    
    return(a[qtde-1] > maior_anterior) ? a[qtde-1] : maior_anterior;
}

int main() {
    int qtde, valor;

    printf("Quantos valores gostaria de adicionar ao vetor? ");
    scanf("%d", &qtde);

    int *a = CriarVetInt(qtde); 

    for(int i = 0; i < qtde; i++) {
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &valor);
        a[i] = valor;
    }

    printf("O maior elemento do vetor e %d\n", MaiorElemento(a, qtde));

    free(a);
    return 0;
}