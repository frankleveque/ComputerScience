# encoding: utf-8

##
# @file 
# @brief Solves the 4th problem of Project Euler using Python. 
# @author Frank Leveque
# @code
# A palindromic number reads the same both ways. 
# The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
#
# Find the largest palindrome made from the product of two 3-digit numbers.
# @endcode
# 

## stores largest palindrome found
largest = 0

## function that checks if a number is a palindrome
def isPalindrome(num):
    temp = str(num)
   
    #quick test to see if first and last chars match
    if temp[0] != temp[len(str(num)) -1]:
        return False
    
    firstcounter = 0
    lastcounter = len(temp) -1
    while firstcounter < lastcounter:
        if temp[firstcounter] != temp[lastcounter]:
            return False
        firstcounter+=1
        lastcounter-=1

    return True

#multiplies three digit numbers and checks if result is a palindrome
for i in range(100,1000):
    for j in range(100,1000):
        if i*j > largest:
            if(isPalindrome(i*j)):
                largest = i*j

print (largest)


