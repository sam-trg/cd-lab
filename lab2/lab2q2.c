// WAP to discard preprocessor directives from the given input ‘C’ file.

#include <stdio.h>

#include <stdio.h>

int main() {
    FILE *fp = fopen("file1.c", "r");
    FILE *fp2 = fopen("file3.c", "w");
    if (!fp) return 1;
    int c;
    while ((c = getc(fp)) != EOF) {
        if (c == '#') while ((c = getc(fp)) != EOF && c != '\n');
        if (c != EOF) putc(c, fp2);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
