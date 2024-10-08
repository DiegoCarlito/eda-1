#include <stdio.h>
int main() {
    int numero, *ptr;
    numero = 79417;
    printf("%d\n", numero);
    ptr = &numero;
    printf("%p\n", ptr);
    *ptr = 90560;
    printf("%d\n", *ptr);
    return 0;
}
