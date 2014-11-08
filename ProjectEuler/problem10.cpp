/**
 * @file
 * @author Frank Leveque
 * @brief Solves the 10th problem of Project Euler using C++.
 * @code
 *The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 * @endcode
 *
 */

#include <iostream>
#include <projecteulertools.hpp>

int main()
{
    unsigned long long primeSum = 0;

    for (unsigned long i =0; i < 2000000; ++i){
        if(primalityTest(i)){
            primeSum += i;
        }
    }
    std::cout << primeSum;

    //pause to view console output
    std::cin.get();
    return 0;
}
