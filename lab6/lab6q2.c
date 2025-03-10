#include <stdio.h>
#include <stdlib.h>

const char *input;
char lookahead;

void error() {
    printf("Syntax Error\n");
    exit(1);
}

void match(char expected) {
    if (lookahead == expected) {
        lookahead = *++input;
    } else {
        error();
    }
}

void S();
void U();
void V();
void W();

void S() {
    U();
    V();
    W();
}

void U() {
    if (lookahead == '(') {
        match('(');
        S();
        match(')');
    } else if (lookahead == 'a') {
        match('a');
        S();
        match('b');
    } else if (lookahead == 'd') {
        match('d');
    } else {
        error();
    }
}

void V() {
    if (lookahead == 'a') {
        match('a');
        V();
    }
}

void W() {
    if (lookahead == 'c') {
        match('c');
        W();
    }
}

void parse(const char *str) {
    input = str;
    lookahead = *input;
    S();
    if (lookahead == '\0') {
        printf("Parsing successful\n");
    } else {
        error();
    }
}

int main() {
    const char *test_input = "a(d)c"; // Modify this input for testing
    parse(test_input);
    return 0;
}
