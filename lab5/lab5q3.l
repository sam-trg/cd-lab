%{
#include <stdio.h>
int pos_int = 0;
int neg_int = 0;
int pos_float = 0;
int neg_float = 0;
%}

%%
-?[0-9]+\.[0-9]+    {
    if(yytext[0] == '-')
        neg_float++;
    else
        pos_float++;
}
-[0-9]+    { neg_int++; }
[0-9]+     { pos_int++; }
.|\n       ; /* Ignore other characters */
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter numbers (Ctrl+D to end):\n");
    yylex();
    printf("\nResults:\n");
    printf("Positive Integers: %d\n", pos_int);
    printf("Negative Integers: %d\n", neg_int);
    printf("Positive Floating Points: %d\n", pos_float);
    printf("Negative Floating Points: %d\n", neg_float);
    return 0;
}