#include <stdio.h>
#include <stdlib.h>
#include "./lab/VetoresC.h"

void LocalizarValor(int *a, int qtde, int infoValor, int posicao) {
    if (posicao >= qtde) {
        return;
    }

    if (a[posicao] == infoValor) {
        printf("O valor %d foi encontrado na posicao %d.\n", infoValor, posicao+1);
    }

    LocalizarValor(a, qtde, infoValor, posicao + 1);
}

int main() {
    int qtde, valor, infoValor;

    printf("Quantos valores gostaria de adicionar ao vetor? ");
    scanf("%d", &qtde);

    int *a = CriarVetInt(qtde); 

    for(int i = 0; i < qtde; i++) {
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &valor);
        a[i] = valor;
    }

    printf("Gostaria de saber a localizacao de qual valor presente no vetor? ");
    scanf("%d", &infoValor);

    printf("Aqui esta o resultado: \n");
    LocalizarValor(a, qtde, infoValor, 0);

    free(a);
    return 0;
}