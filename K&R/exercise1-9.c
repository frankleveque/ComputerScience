/* write a program to copy its input to its output, replacing each string of one
 * or more blanks by a single blank */

#include <stdio.h>

int main()
{
    int c = 0;
    int blanks = 0;

    while((c=getchar()) != EOF){
        if(c==' ')
            blanks+=1;
        else{
            if(blanks > 0){
                printf(" ");
                blanks=0;
            }
            printf("%c", c);
        }
    }
}
