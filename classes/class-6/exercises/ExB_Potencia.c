#include <stdio.h>

int Potencia(int x, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    return x*Potencia(x,n-1);
}

int main() {
    int x, n;

    do {
        printf("Digite x: ");
        scanf("%d", &x);

        printf("Digite n: ");
        scanf("%d", &n);

        printf("\n");

    } while(x<0 || n<0);

    printf("%d elevado a %d e %d", x, n, Potencia(x, n));

    return 0;
}