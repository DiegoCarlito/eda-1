#include <stdlib.h>
#include <stdio.h>

int* CriarVetInt(int tamVet) {
    int *vet_int;
    vet_int = (int*)calloc(tamVet, sizeof(int));
    return vet_int;
}

float* CriarVetFloat(int tamVet) {
    float *vet_float;
    vet_float = (float*)calloc(tamVet, sizeof(float));
    return vet_float;
}

void IncluirCaracter(char *pvetcar, int ptammax, int *pqtde, char caractere) {
    if (*pqtde < ptammax) {
        pvetcar[*pqtde] = caractere;
        (*pqtde)++;
    } else {
        printf("Erro: O vetor está cheio. Não é possível incluir o caractere.\n");
    }
}

void ExcluirCaracter(char *pvetcar, int *pqtde, char caractere) {
    int i, j;

    for (i = 0; i < *pqtde; i++) {
        if (pvetcar[i] == caractere) {
            
            for (j = i; j < *pqtde - 1; j++) {
                pvetcar[j] = pvetcar[j + 1];
            }
            (*pqtde)--;
            return;
        }
    }

    printf("Erro: O caractere não foi encontrado no vetor.\n");
}
 
int IncluirValor(float *pvalores, float pv, int pcapacidade, int *ptamanho) {
    if (*ptamanho < pcapacidade) {
        pvalores[*ptamanho] = pv;
        (*ptamanho)++;
        return 1;
    } else {
        return 0;
    }
}

int ExcluirValor(float *pvalores, int pcapacidade, int *ptamanho, float pv) {
    for (int i = 0; i<pcapacidade; i++) {
        if (pvalores[i] == pv) {
            for (int j = i; j < *ptamanho-1; j++) {
                pvalores[j] = pvalores[j+1];
            }
            (*ptamanho)--;
            return 1;
        }
    }
    return 0;
}

int EIgual(int *pveta, int *pvetb, int ptama, int ptamb) {
    if (ptama == ptamb) {
        for (int i = 0; i < ptama; i++) {
            if(pveta[i] != pvetb[i]) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}
