#include <stdio.h>

float celsius_para_farenheit(float valor) {
    return valor * 1.8 + 32;
}

float fahrenheit_para_celsius(float valor) {
    return (valor - 32) / 1.8;
}

int main(void) {
    char opcao;
    float valor, resultado;
    
    do {
        printf("---------- MENU -----------\n");
        printf("C - Fahrenheit para Celsius\n");
        printf("F - Celsius para Fahrenheit\n");
        printf("S - Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        if (opcao == 'C' || opcao == 'c') {
            scanf("%f", &valor);
            resultado = fahrenheit_para_celsius(valor);
            printf("%.2f Fahrenheit = %.2f Celsius\n", valor, resultado);
        } else if (opcao == 'F' || opcao == 'f') {
            scanf("%f", &valor);
            resultado = celsius_para_farenheit(valor);
            printf("%.2f Celsius = %.2f Fahrenheit\n", valor, resultado);
        } else if (opcao == 'S' || opcao == 's') {
            printf("Saindo...\n");
        } else {
            printf("Opcao Invalida\n");
        }

    } while (opcao != 'S' && opcao != 's');

    return 0;
}