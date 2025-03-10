%{
#include <stdio.h>
int words = 0;
int chars = 0;
int blanks = 0;
int lines = 0;
%}

%%
[[:space:]]+    { blanks += yyleng; chars += yyleng; }
\n              { lines++; chars++; }
[[:alnum:]]+    { words++; chars += yyleng; }
.               { chars++; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("\nResults:\n");
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);
    printf("Blanks: %d\n", blanks);
    printf("Lines: %d\n", lines);
    return 0;
}