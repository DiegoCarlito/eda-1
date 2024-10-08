#include <stdio.h>

int SomarDigitos(char n[]) {
    if(n[0]== '\0') {
        return 0;
    }
    
    int digito = n[0] - '0';

    return digito + SomarDigitos(n+1);
}

int main() {
    char n[30];
    printf("Digite um numero: ");
    scanf("%s", n);

    printf("A soma dos digitos e: %d", SomarDigitos(n));

    return 0;
}