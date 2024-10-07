#include <stdio.h>
int main() {
    char caractere;
    int inteiro;
    float pFlutuante;
    // Exemplo de uso do scanf com char
    scanf("%c", &caractere);
    printf("Caractere digitado: %c\n", caractere);
    // Limpa o buffer do teclado
    while (getchar() != '\n');
    // Exemplo de uso do scanf com int
    scanf("%d", &inteiro);
    printf("Número inteiro digitado: %d\n", inteiro);
    // Exemplo de uso do scanf com float
    scanf("%f", &pFlutuante);
    printf("Ponto flutuante digitado: %.2f\n", pFlutuante);
    return 0;
}