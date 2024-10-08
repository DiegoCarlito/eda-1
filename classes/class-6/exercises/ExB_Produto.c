#include <stdio.h>

int Produto(int a, int b) {
    int cont = b;
    if (cont == 0) {
        return 0;
    } else {
        cont -= 1;
    }
    
    return a + Produto(a, cont);
}

int main() {
    int a, b;
    do {
        printf("Digite a: ");
        scanf("%d", &a);
        
        printf("Digite b: ");
        scanf("%d", &b); 

        printf("\n");
    } while(a<0 || b<0);

    printf("O produto de a por b e %d\n",Produto(a, b));

    return 0;
}