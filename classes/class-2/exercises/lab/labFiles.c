/*
Seu objetivo é fazer um programa que leia o nome de um arquivo texto e faça 
uma função word2vec que crie um arquivo de saída contendo uma palavra do texto
de entrada por linha.
*/

/*
- Seu arquivo de saída não deve conter palavras repetidas.
- Tratamento de StopWords: pontuações e palavras com menos de 4 caracteres devem ser desconsideradas.
- O nome do seu arquivo de saída deve ter o mesmo nome do arquivo de entrada acrescido do sufixo "_Vocabulo". Por exemplo: Se o nome do arquivo de entrada é Texto.txt, seu arquivo de saída deverá ser Texto_Vocaculo.txt.
- Você não deve considerar letras maiúsculas ou minúsculas para diferenciar uma palavra de outra. Exemplo de uma mesma palavra: Hoje, hoje, HOJE. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se uma palavra é uma stopword (menos de 4 caracteres).
int isStopWord(char *word) {
    return strlen(word) < 4;
}

// Função para remover a pontuação do final de uma palavra.
void removePunctuation(char *word) {
    int length = strlen(word);
    while (length > 0 && ispunct(word[length - 1])) {
        word[length - 1] = '\0';
        length--;
    }
}

int namefilepointposition(char *fullname) {
    int i;
    for (i = 0; i < strlen(fullname); i++) {
        if (fullname[i] == '.')
            break;
    }
    if (i >= strlen(fullname))
        return -1;
    else
        return i;
}

int word2vec(char *pNomeTxtEntrada) {
    FILE *arqent, *arqsaida;
    char nomarq[50];

    int pointidx = namefilepointposition(pNomeTxtEntrada);
    int pp;

    // Gerando o nome do arquivo de saída.
    if (pointidx >= 0) {
        for (pp = 0; pp < pointidx; pp++)
            nomarq[pp] = pNomeTxtEntrada[pp];
        nomarq[pp] = '\0'; // Fim da string.
    } else
        strcpy(nomarq, pNomeTxtEntrada);

    strcat(nomarq, "_Vocabulo.txt");
    printf("\nRecebi o nome do arquivo de saída: %s\n", nomarq);

    // Abertura dos arquivos de entrada e saída.
    arqent = fopen(pNomeTxtEntrada, "r");
    if (arqent == NULL) {
        puts("Não foi possível ler o arquivo!!!");
        exit(1);
    }

    arqsaida = fopen(nomarq, "w");
    if (arqsaida == NULL) {
        puts("Não foi possível gravar o arquivo de saída!!!");
        exit(1);
    }

    // Conjunto de palavras únicas.
    char uniqueWords[1000][30];
    int uniqueCount = 0;

    char word[30];

    while (fscanf(arqent, "%s", word) != EOF) {
        // Converta a palavra para letras minúsculas.
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        removePunctuation(word);

        if (!isStopWord(word)) {
            int isUnique = 1;
            for (int i = 0; i < uniqueCount; i++) {
                if (strcmp(uniqueWords[i], word) == 0) {
                    isUnique = 0;
                    break;
                }
            }
            if (isUnique) {
                strcpy(uniqueWords[uniqueCount], word);
                uniqueCount++;
                fprintf(arqsaida, "%s\n", word);
            }
        }
    }

    fclose(arqent);
    fclose(arqsaida);

    return 1;
}

int main() {
    char nomearq[30];
    printf("Entre com o nome do arquivo de entrada: ");
    scanf("%s", nomearq);
    if (!word2vec(nomearq))
        printf("\nErro na geração do vocabulário!");
    else
        printf("\nVocabulário gerado com sucesso!");

    return 0;
}
