/**
 * @file
 * @author Frank Leveque
 * @brief Solves the 5th problem of Project Euler using C++.
 * @code
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10
 * without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of
 * the numbers from 1 to 20?
 * @endcode
 *
 */

#include <iostream>
#include <cstdio>

//! function that checks if number is evenly divisible by all numbers
//! from 1 to 20 inclusive
bool checkNumber(int number)
{
	for (int i = 1; i <= 20; i++)
    {
		if (number%i != 0){
			//number is not evenly divisible by i
			return false;
		}
	}
	return true;
}

int main()
{
	bool finalNumberFound = false;
	int startingNumber = 1;

	while (!finalNumberFound)
	{
		if(!checkNumber(startingNumber)){
			startingNumber++;
		}else{
			std::cout << startingNumber;
			break;
		}
	}
    //pause
    std::cin.get();
	return 0;
}

