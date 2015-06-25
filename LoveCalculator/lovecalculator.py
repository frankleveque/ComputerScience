##
# @file 
# @author Frank Leveque
#
# @brief Simple Love Calculator implementation.
# 
# There are different ways of making a love calculator.
# This one removes duplicate characters, converts to lowercase,
# then adds the numerical value of remaining characters together.
# The love percentage is the remainder of that sum divided by 101
# 

import sys

while(True):
    print '\n' + "##Welcome to the Love Calculator###"

    personA = raw_input('Enter Person A\'s name or \'exit\' to quit: ').lower()
    personB = raw_input('Enter Person B\'s name or \'exit\' to quit: ').lower()

    if personA == "exit" or personB == "exit":
        print "quitting..."
        sys.exit()

    if personA != "" and personB != "":
        joinedString = personA +  personB
        
        #convert joinedString to set which is a list, then join back into string
        deduplicated = "".join(set(joinedString))

        numericalValue = 0

        for c in deduplicated:
            sys.stdout.write(str(ord(c)) + " ")
            numericalValue += ord(c)
        
        print '\n' + "Your calculated love percentage is: " + str(numericalValue%101) + "%!"
    else:
        print "Error: Empty value for Person A and/or Person B "
