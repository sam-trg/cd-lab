%{
#include <stdio.h>
int scanf_count = 0;
int printf_count = 0;
%}

%%
"scanf"    { scanf_count++; printf("READ"); }
"printf"   { printf_count++; printf("WRITE"); }
.|\n       { printf("%s", yytext); }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <input-file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(!file) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    yyin = file;
    yylex();
    
    printf("\nResults:\n");
    printf("Number of scanf found: %d\n", scanf_count);
    printf("Number of printf found: %d\n", printf_count);

    fclose(file);
    return 0;
}