
'''
1 ADD - ADD
2 SUB - SUBTRACT
3 STA - STORE 
5 LDA - LOAD
6 BRA - BRANCH/JUMP
7 BRZ - BRANCH IF ZERO
8 BRP - BRANCH IF POSITIVE

901 INP - INPUT
902 OUT - OUTPUT
000 HLT - HALT/COFFEE

DAT - DATA

[LABEL] [OP] [Mailbox/Value]
MYLABEL DAT 444
DAT 444
LOOP BRZ END
END HLT
'''

import sys
import re 


def processInstruction(ins):
    assert len(ins) == 2 or len(ins) == 3
    print ins



for a in sys.argv[1:]:
    with open(a) as f:
        data = f.readline()
        while data != "":

            if data == '\n':
                data = f.readline()
                continue
            data = data.split() 
          
            processInstruction(data)

            data = f.readline()
