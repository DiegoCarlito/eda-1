#include <stdio.h>

int Fatorial(int x) {
    if (x==1) {
        return 1;
    } else {
        return x*Fatorial(x-1);
    }
}

int main() {
    printf("%d\n",Fatorial(5));
    return 0;
}