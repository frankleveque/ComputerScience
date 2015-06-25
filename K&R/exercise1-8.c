/* write a program to count blanks, tabs, and newlines */

#include <stdio.h>

int main()
{
    int c; 
    int nl = 0;
    
    /* using \n as new line character and ignoring \r
     * will work on Unix, Mac OS X, and Windows */

    while((c = getchar()) != EOF)
        if(c=='\n' | c==' ' | c=='\t')
            ++nl;
    printf("%d blanks, tabs, or new lines\n", nl);
}
