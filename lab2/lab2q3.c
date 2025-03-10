// WAP to discard preprocessor directives from the given input ‘C’ file.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while" };

int is_keyword(char *word) {
    for (int i = 0; i < 32; i++)
        if (!strcmp(word, keywords[i])) return 1;
    return 0;
}

int main() {
    FILE *fp = fopen("file1.c", "r");
    if (!fp) return 1;

    char word[20];
    int i = 0, c;

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            word[i++] = c;
            if (i >= 19) i = 19;  
        } else {
            if (i > 0) {
                word[i] = '\0';
                if (is_keyword(word)) {
                    for (int j = 0; word[j]; j++) word[j] = toupper(word[j]);
                    printf("%s\n", word);
                }
                i = 0;
            }
        }
    }

    fclose(fp);
    return 0;
}
