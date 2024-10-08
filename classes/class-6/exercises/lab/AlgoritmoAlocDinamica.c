#include <stdio.h>
#include <stdlib.h>
#include "VetoresC.h"

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    float *v = CriarVetFloat(100);

    int valoresInseridos = 0;
    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        float valor;
        scanf("%f", &valor);

        if (IncluirValor(v, valor, 100, &valoresInseridos) == 0) {
            printf("Erro: O vetor esta cheio. Não é possível incluir mais valores.\n");
            break;
        }
    }

    float soma = 0.0;
    int numeradorInferiorAoDenominador = 0;

    for (int i = 0; i < n; i++) {
        if (i + 1 < v[i]) {
            numeradorInferiorAoDenominador++;
        }
        soma += (i + 1) / v[i];
    }

    printf("Valor da serie: %f\n", soma);
    printf("Quantidade de termos com numerador inferior ao denominador: %d\n", numeradorInferiorAoDenominador);

    free(v);

    return 0;
}
