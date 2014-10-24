# encoding: utf-8

##
# @file 
# @brief Simple Fizzbuzz implementation (1 to 100) in python. 
# @author Frank Leveque
# @code
# If the number is divisible by 3 print "Fizz"
# If the number is divisible by 5 print "Buzz"
# If the number is divisible by 3 and 5 print "FizzBuzz"
# @endcode
# 

for i in range(1,101):
    if i%15==0:
        print "FizzBuzz"
    elif i%3==0:
        print "Fizz"
    elif i%5==0:
        print "Buzz"
    else:
        print i
