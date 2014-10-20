##
# @file 
# @author Frank Leveque
# @brief Solves the 3rd problem of Project Euler using Python. 
# @code
# The prime factors of 13195 are 5, 7, 13 and 29.
#
# What is the largest prime factor of the number 600851475143 ?
# @endcode
#

import math

## Primality check function from 2 to sqrt(n) rounded up
def isPrime(num):
    if num <2:
        return False;
    elif ((num == 2)|(num == 3)):
        return True;
    elif(num%2 == 0):
        return False;
    else:

        for i in range(2,int(math.ceil(math.sqrt(num)))+1):
            if(num%i == 0):
                return False;
    return True;
       
## Returns list of factors
def HighestPrimeFactor(number):
    currentNumber = number
    factor = 1 
    factorList = []
    while(not factor > currentNumber):
        if currentNumber%factor == 0:
            factorList.append(factor)
            currentNumber = currentNumber/factor
        factor += 1
    return factorList

## reverse sort the list so highest number is tested for primality first 
# then print final answer and break
for num in sorted(HighestPrimeFactor(600851475143), reverse=True):
    if isPrime(num):
        print num;
        break;

