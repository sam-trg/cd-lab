/*WAP to display size of file*/

#include<stdio.h>
#include<stdlib.h>

int main(void) {
    FILE* fp = fopen("source.txt", "rb");
    if(!fp) {
        printf("Error opening file.");
        EXIT_FAILURE;
    }

    long int size;
    byte byte;
    fscanf(fp, "%x", &byte);
    size++;
    while(byte!='\0'){
        fscanf(fp, "%x", byte);
        size++;
    }
    printf("Size of file is %ld bytes.\n", size);
    return 0;
}
