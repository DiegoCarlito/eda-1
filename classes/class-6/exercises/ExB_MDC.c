#include <stdio.h>

int FazerMDC(int a, int b) {
    if(a%b==0) {
        return b;
    } else {
        FazerMDC(b, a%b);
    }
}

int main(void) {
    int a, b, maior;

    printf("Digite a: ");
    scanf("%d", &a);
    printf("Digite b: ");
    scanf("%d", &b);

    if (a<b) {
        maior = b;
        b = a;
        a = maior;
    }

    printf("O mdc entre %d e %d e: %d\n",a, b, FazerMDC(a, b));

    return 0;
}