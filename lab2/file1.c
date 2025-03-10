// WAP to remove single line and multiline comments in a C file
/*This is  a multiline comment*/
/* THIS IS ALSO A MULT
TILINE
COMMENT*/
// random single line comment
//sdsd smds/dm///sdmsomdosmd///mdosmods/sm//
/********adaiosndasodnadasd
 * asadnaodna
 */
case
char #pragma omp
#include <stdio.h>
auto
break #pragma ompcase
char
int main() {
    FILE* fp1 = fopen("file1.c", "r");
    FILE* fp2 = fopen("file2.c", "w");
    int c;
    while(c!=EOF) {
        c = getc(fp1);
        if(c=='/') {
            c = getc(fp1);
            if(c=='/'){
                while(c!='\n'){
                    c = getc(fp1);
                }
            }
            else if(c=='*') {
                c = getc(fp1);
                while(c!='\n') {
                    c = getc(fp1);
                    if(c=='*') {
                        c = getc(fp1);
                        if(c=='/'){
                            break;
                        }
                    }

                }
            }
        }
        putc(c, fp2);
    }
}