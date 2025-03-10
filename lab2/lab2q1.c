// WAP to remove single line and multiline comments in a C file

#include <stdio.h>

int main() {
    FILE* fp1 = fopen("file1.c", "r");
    FILE* fp2 = fopen("file2.c", "w");
    if (!fp1 || !fp2) return 1; 

    int c;
    while ((c = getc(fp1)) != EOF) {
        if (c == '/') {
            int next = getc(fp1);
            if (next == '/') {
                while ((c = getc(fp1)) != EOF && c != '\n');
                if (c == '\n') putc(c, fp2);
            } else if (next == '*') {
                while ((c = getc(fp1)) != EOF) {
                    if (c == '*' && (next = getc(fp1)) == '/') break;
                }
            } else {
                putc(c, fp2);
                putc(next, fp2);
            }
        } else {
            putc(c, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
