#include <stdio.h>
// Função para trocar o valor de duas variáveis float:
void trocarValores(float *ptr1, float *ptr2) {
    float temp = *ptr1; //Armazena o valor de ptr1 em uma variável
    *ptr1 = *ptr2; //Atribui o valor de ptr2 a ptr1
    *ptr2 = temp; //Atribui o valor temporário a ptr2
}
int main() {
    float a = 3.14;
    float b = 2.71;
    printf("Valores originais: a = %.2f, b = %.2f\n", a, b);
    //Chama a função para trocar os valores de 'a' e 'b':
    trocarValores(&a, &b);
    printf("Valores trocados: a = %.2f, b = %.2f\n", a, b);
    return 0;
}