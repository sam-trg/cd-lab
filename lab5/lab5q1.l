%{
#include <stdio.h>
#include <stdlib.h>

int vowels = 0;
int consonants = 0;
extern FILE *yyin; // Declare input file pointer
%}

%%
[aeiouAEIOU]    { vowels++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]    { consonants++; }
.               ; /* Ignore other characters */
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error opening file");
        return 1;
    }

    yylex();
    fclose(yyin);

    printf("\nResults:\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0; 
}

