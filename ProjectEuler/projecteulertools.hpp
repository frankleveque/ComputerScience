#ifndef PROJECTEULERTOOLS_HPP
#define PROJECTEULERTOOLS_HPP

/**
 * @file
 * @author Frank Leveque
 * @brief Useful functions for project euler problems
 *
 */



/** inefficient way to check primality
 * returns false for n < 2
 * returns true for n == 2
 * looks for primes from 3 to n-1
 * if a number from 3 to n-1 is divisible without a remainder, return false
 **/
bool primalityTest(unsigned long n)
{
    if(n < 2) {
        return false;
    } else if(n==2) {
        return true;
    } else {
        unsigned long counter = 2;
        while (counter < n) {
            if(n % counter == 0) {
                return false;
            }
            ++counter;
        }
        return true;
    }
}

#endif
