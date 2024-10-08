#include <stdio.h>
#include <stdlib.h>
#include "./lab/VetoresC.h"

long int somavet(int *a, int qtde) {
    if (qtde <= 0) {
        return 0;
    }
    return a[qtde - 1] + somavet(a, qtde-1);
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

    printf("A soma dos elementos do vetor e %ld\n", somavet(a, qtde));

    free(a);
    return 0;
}