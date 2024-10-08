#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void contrario(char *s, char *c, int index) {
    if (s[index] != '\0') {
        contrario(s, c, index + 1);
        c[strlen(s) - index - 1] = s[index];
    } else {
        c[index] = '\0';
    }
}

int main() {
    char s[30];
    char c[30];

    printf("Imprime reverso\n\n");
    printf("Digite a string: ");
    gets(s);

    contrario(s, c, 0);
    int result = strcmp(s, c);
    if(result == 0) {
        printf("E um palindromo!\n");
    } else {
        printf("Nao e um palindromo!\n");
    }
    

    return 0;
}
