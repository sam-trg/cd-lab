/*WAP to reverse contents of a file and save to another*/

#include <stdio.h>
#include <stdlib.h>

struct Stack{
    char data[4096];
    int tos;
};

char pop(struct Stack* sp) {
    char c = sp->data[sp->tos];
    sp->tos--;
    return c;
}

void push(char c, struct Stack* sp) {
    sp->tos++;
    sp->data[sp->tos] = c;
}


int main(void) {
    
    FILE* fp1 = fopen("source.txt", "r");
    if(!fp1) {
        perror("Could not open source file.");
        EXIT_FAILURE;
    }

    struct Stack* sp;
    sp->tos=-1;

    char curr = getc(fp1);
    push(curr, sp);

    while(curr!=EOF) {
        curr = fgetc(fp1);
        push(curr, sp);
    }
    fclose(fp1);

    FILE* fp2 = fopen("dest.txt", "w");
    if(!fp2) {
        fclose(fp1);
        perror("Could not open or create destination file.");
        EXIT_FAILURE;
    }

    //get rid of reversed EOF character
    pop(sp);

    while(sp->tos > -1) {
        fputc(pop(sp), fp2);
    }

    fclose(fp2);

    printf("File reversal successful.\n");

    return 0;
}