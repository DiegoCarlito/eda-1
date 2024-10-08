#ifndef VETORESC_H
#define VETORESC_H

int* CriarVetInt();

float* CriarVetFloat();

void IncluirCaracter(char *pvetcar, int ptammax, int *pqtde, char caractere);

void ExcluirCaracter(char *pvetcar, int *pqtde, char caractere);

int IncluirValor(float *pvalores, float pv, int pcapacidade, int *ptamanho);

int ExcluirValor(float *pvalores, int pcapacidade, int *ptamanho, float pv);

int EIgual(int *pveta, int *pvetb, int ptama, int ptamb);

#endif