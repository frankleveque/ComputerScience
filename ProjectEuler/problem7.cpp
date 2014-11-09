/*
########
#

########
*/
/**
 * @file
 * @author Frank Leveque
 * @brief Solves the 7th problem of Project Euler using C++.
 * @code
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 * @endcode
 *
 */

#include <iostream>
#include <projecteulertools.hpp>

int numberOfPrimes = 0;
int counter = 0;

int main()
{

    while(1) {
        if(primalityTest(counter))
            numberOfPrimes += 1;
        if (numberOfPrimes == 10001) {
            std::cout << counter;
            break;
        }
        ++counter;
    }
    return 0;
}
