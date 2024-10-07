#include <stdio.h>

int main() {
    FILE *fp;
    char ch;
    
    // Tente abrir o arquivo
    fp = fopen("ex1.c", "r");
    
    // Verifique se o arquivo foi aberto com sucesso
    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1; // Encerre o programa com código de erro
    }
    
    // Leia e imprima os caracteres do arquivo
    while (1) {
        ch = fgetc(fp);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }
    
    // Feche o arquivo
    fclose(fp);
    
    return 0;
}
