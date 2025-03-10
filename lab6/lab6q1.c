#include <stdio.h>
#include <stdlib.h>

const char *input;
char lookahead;

void error() {
    printf("Syntax Error\n");
    exit(1);
}

void advance() {
    lookahead = *input++;
}

void S();
void T();

void S() {
    if (lookahead == 'a' || lookahead == '>') {
        advance();
    } else if (lookahead == '(') {
        advance();
        T();
        if (lookahead == ')') {
            advance();
        } else {
            error();
        }
    } else {
        error();
    }
}

void T() {
    S();
    while (lookahead == ',') {
        advance();
        S();
    }
}

void parse(const char *str) {
    input = str;
    advance();
    S();
    if (lookahead != '\0') error();
    printf("Parsing Successful\n");
}

int main() {
    const char *test_cases[] = {
        "a", ">", "(a)", "(a,>)", "(a,a,>)", "(>)", "(>)", "(a, (>, a))", NULL
    };

    for (int i = 0; test_cases[i]; i++) {
        printf("Testing: %s\n", test_cases[i]);
        parse(test_cases[i]);
    }

    return 0;
}
