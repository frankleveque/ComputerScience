/**
 * @file
 *
 * @author Frank Leveque
 * @brief Simple Fizzbuzz implementation (1 to 100) in C.
 * @code
 * If the number is divisible by 3 print "Fizz"
 * If the number is divisible by 5 print "Buzz"
 * If the number is divisible by 3 and 5 print "FizzBuzz"
 * @endcode
 *
 */

#include <stdio.h>

int main()
{
    for(int i=1; i<101; ++i){
        if (i%15 == 0)
            printf("%s\n", "FizzBuzz");
        else if (i%3 == 0)
            printf("%s\n", "Fizz");
        else if (i%5 == 0)
            printf("%s\n", "Buzz");
        else
            printf("%i\n", i);
    }

    //pause to view output
    getchar();

    return 0;
}
