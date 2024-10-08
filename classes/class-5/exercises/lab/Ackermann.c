#include <stdio.h>

int AckermannRecursivo(int m, int n) {
    if(m==0) {
        return n+1;
    }

    if(m>0 && n==0) {
        return AckermannRecursivo(m-1, 1);
    }

    if(m>0 && n>0) {
        return AckermannRecursivo(m-1, AckermannRecursivo(m, n-1));
    }
}

int main(void) {
    int m, n;
    
    printf("Digite m: ");
    scanf("%d", &m);

    printf("Digite n: ");
    scanf("%d", &n);
    if (m<0 || n<0) {
        printf("Insira valores positivos!\n");
    } else {
        printf("O valor da funcao de Ackermann para m=%d e n=%d e %d\n", m, n, AckermannRecursivo(m, n));
    }

    return 0;
}
