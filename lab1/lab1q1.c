/*WAP to count the no. of chars and lines in a file*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    FILE* fp = fopen("source.txt", "r");
    
    if(!fp) {
        perror("Error opening source file");
        EXIT_FAILURE;
    }

    int charcnt;
    int linecnt=0;

    char c = fgetc(fp);
    charcnt = 1;

    while(c!=EOF) {
        
        c = fgetc(fp);
        charcnt++;

        if(c=='\n') linecnt++;
    }

    if(c!='\n') linecnt++;

    fclose(fp);

    printf("Number of chars and lines respectively are %d and %d.\n", charcnt, linecnt);
    
    return 0;

}