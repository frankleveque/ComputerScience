/**
 * @file
 * @author Frank Leveque
 * @brief Solves the 9th problem of Project Euler using C++.
 * @code
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a2 + b2 = c2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 * @endcode
 *
 */

#include <iostream>

int main()
{
    for(int a=0; a<=1000; ++a) {

        for(int b=0; b<=1000; ++b) {

            for(int c=0; c<=1000; ++c) {
                int a2 = a*a;
                int b2 = b*b;
                int c2 = c*c;
                int finalValue = a+b+c;

                if((a2 + b2 == c2) & (c > b) & (b > a) & (finalValue == 1000)) {
                    std::cout << a * b * c << std::endl;
                }
            }
        }
    }
    //pause to view console output
    std::cin.get();
    return 0;
}
