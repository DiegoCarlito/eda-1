#include <stdio.h>

int CompararStrings(char s1[], char s2[]) {
    if (s1[0]=='\0' && s2[0]=='\0') {
        return 1;
    } 

    if (s1[0] != s2[0]) {
        return 0;
    }

    return CompararStrings(&s1[1], &s2[1]);
}

int main() {
    char str1[30], str2[30];

    printf("Digite a primeira string: ");
    scanf("%s", str1);

    printf("Digite a segunda string: ");
    scanf("%s", str2);
    
    if (CompararStrings(str1, str2)) {
        printf("Sao iguais\n");
    } else {
        printf("Nao sao iguais\n");
    }
    
}