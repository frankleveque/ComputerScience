/**
 * @file
 * @author Frank Leveque
 * @brief Solves the 6th problem of Project Euler using C++.
 * @code
 * The sum of the squares of the first ten natural numbers is,
 * 12 + 22 + ... + 102 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)2 = 552 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten
 * natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 * @endcode
 *
 */

#include <iostream>
#include <string>

//! returns sum of every number from 1 to num (inclusive) squared
int sumOfNumSquared(int num)
{
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        sum += i*i;
    }
    return sum;

}
//! returns square of the sum of every number from 1 to num (inclusive)
int squareOfSum(int num)
{
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        sum += i;
    }
    return sum*sum;
}

int main()
{
    int number = 100;

    std::cout << squareOfSum(number) - sumOfNumSquared(number) << std::endl;

    //pause to view console
    std::cin.get();

    return 0;
}

