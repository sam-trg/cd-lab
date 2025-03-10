#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

const char *keywords[] = {"int", "float", "if", "else", "while", "return", "for", "char", "double", "void"};
#define KEYWORDS_COUNT (sizeof(keywords) / sizeof(keywords[0]))

int isKeyword(const char *word) {
    for (int i = 0; i < KEYWORDS_COUNT; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(char c) {
    return strchr("+-*/%<>=!&|", c) != NULL;
}

int isSpecialSymbol(char c) {
    return strchr("{}()[],;", c) != NULL;
}

int isNumber(const char *word) {
    for (int i = 0; word[i]; i++) {
        if (!isdigit(word[i]) && word[i] != '.') {
            return 0;
        }
    }
    return 1;
}

void identifyTokens(const char *code) {
    char word[50];
    int index = 0;
    
    for (int i = 0; code[i] != '\0'; i++) {
        if (isalnum(code[i]) || code[i] == '.') {
            word[index++] = code[i];
        } else {
            if (index > 0) {
                word[index] = '\0';
                if (isKeyword(word)) {
                    printf("Keyword: %s\n", word);
                } else if (isNumber(word)) {
                    printf("Numerical Constant: %s\n", word);
                } else {
                    printf("Identifier: %s\n", word);
                }
                index = 0;
            }
            if (isOperator(code[i])) {
                printf("Operator: %c\n", code[i]);
            } else if (isSpecialSymbol(code[i])) {
                printf("Special Symbol: %c\n", code[i]);
            } else if (code[i] == '"') {
                printf("String Literal: \"");
                i++;
                while (code[i] != '\0' && code[i] != '"') {
                    putchar(code[i]);
                    i++;
                }
                printf("\"\n");
            }
        }
    }
}

int main() {
    FILE *file = fopen("file1.c", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    char code[200];
    while (fgets(code, sizeof(code), file)) {
        identifyTokens(code);
    }
    fclose(file);
    return 0;
}