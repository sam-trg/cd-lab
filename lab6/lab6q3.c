#include <stdio.h>
#include <stdlib.h>

const char *input;
int index = 0;

void S();
void A();
void B();

void error() {
    printf("Parsing error at index %d\n", index);
    exit(1);
}

void match(char expected) {
    if (input[index] == expected) {
        index++;
    } else {
        error();
    }
}

void A() {
    if (input[index] == 'b') {
        index++;
        while (input[index] == 'b') {
            index++;
        }
    } else {
        error();
    }
}

void B() {
    match('d');
}

void S() {
    match('a');
    A();
    match('A');
    match('c');
    B();
    match('B');
    match('e');
}

int main() {
    input = "abbAcdeB"; // Change this to test other inputs
    S();
    if (input[index] == '\0') {
        printf("Parsing successful\n");
    } else {
        error();
    }
    return 0;
}
