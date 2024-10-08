#include <stdio.h>

int fibonacci(int f) {
    if(f == 0) {
        return 0;
    }

    if(f == 1) {
        return 1;
    }

    return fibonacci(f-1) + fibonacci(f-2);
}

int main() {
    int f;
    
    printf("Gostaria de saber qual termo de Fibonacci? ");
    do {
        scanf("%d", &f);
        if (f < 0) {
            printf("Digite um valor valido!\n");
        } 
    } while(f < 0);
    
    printf("A termo %d de fibonacci e %d\n", f, fibonacci(f));

    return 0;
}