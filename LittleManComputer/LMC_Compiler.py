
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

'''

import sys
import re 

opCodes = {}
opCodes['add'] = 100
opCodes['sub'] = 200
opCodes['sta'] = 300
opCodes['store'] = 300
opCodes['load'] = 500
opCodes['lda'] = 500
opCodes['branch'] = 600
opCodes['bra'] = 600
opCodes['branchzero'] = 700
opCodes['brz'] = 700
opCodes['branchpositive'] = 800
opCodes['brp'] = 800
opCodes['input'] = 901
opCodes['inp'] = 901
opCodes['output'] = 902
opCodes['out'] = 902
opCodes['halt'] = 000
opCodes['hlt'] = 000
opCodes['coffee'] = 000
opCodes['coffeebreak'] = 000
opCodes['data'] = None
opCodes['dat'] = None

memory = ["0"] * 100
labels = {}


def fixInstructions(instructions):
    '''
    instructions is list of strings representing instructions 
    '''
    
    if not instructions:
        return
    initial = len(instructions)

    # lowercase all
    for i in range(len(instructions)):
        for j in range(len(instructions[i])):
            instructions[i][j] = instructions[i][j].lower()

        
    ops = ['dat', 'data']
    # massage inputs
    for i in range(len(instructions)):
        if len(instructions[i]) == 1:
            print instructions[i],"|1"
            instructions[i] += [0] 
        elif (len(instructions[i]) == 2 and 
            any( op == instructions[i][0] for op in ops)):
            print instructions[i],"|2"
            pass #instructions[i] += [0 

        elif (len(instructions[i]) == 2 and 
            any( op != instructions[i][0] for op in ops)):
            print instructions[i],"|2"
            instructions[i] += [0] 
        
    # check
    for i in range(len(instructions)):
        assert len(instructions[i]) >= 2
    
    assert len(instructions[:]) == initial
    return instructions


def replaceLabels(instructions):
    
    for i in range(len(instructions)):
        if len(instructions[i]) == 3:
            possible = instructions[i][0]
            if possible not in opCodes.keys():
                #defining keyword
                if possible not in labels.keys():
                    labels[instructions[i][0]] = i
                else:
                    print "label [" + possible + "] already defined"
            # remove declaration index
            instructions[i] = instructions[i][1:]
    
   
    
    for i in range(len(instructions)):
        for j in range(len(instructions[i])):
            if (instructions[i][j] not in opCodes.keys() and 
            not str(instructions[i][j]).isdigit()):
                try:
                    instructions[i][j] = labels[instructions[i][j]]
                except KeyError:
                    print "label [" + str(instructions[i][j]) + "]" + " not defined"


    # check
    for i in range(len(instructions)):
        assert len(instructions[i]) == 2



    return instructions



def compileInstruction(instruction):
    '''
    [OP] [Mailbox/Value]
    '''
    assert len(instruction) <= 3 
    assert instruction[0].isalpha() 
    
    op = None
    box = None
    try:
        op = instruction[0]
        opcode = opCodes[op]
        box = int(instruction[1])
        

        if (op == 'hlt' or op == 'halt' or op == 'inp' or op == 'input'):
            return opcode
        elif (op == 'dat' or op == 'data'):
            return int(box)
        else:
            return opcode + int(box)
           
    except KeyError:
           print "Opcode not defined - returning HLT"
           return 0
 




if __name__ == "__main__":

    if len(sys.argv) < 2:
        print "Needs input file(s)"
        sys.exit(0)
    

    for a in sys.argv[1:]:
        

        instructions = [] 
        with open(a) as f:
            data = f.readline()
            while data != "":
                if data == '\n' or data.startswith('#'):
                    data = f.readline()
                    continue
                data = data.split() 
                instructions += [data]
                data = f.readline()



        print instructions 
        instructions = fixInstructions(instructions)
        print "Fixed"
        for p in instructions:
            for s in p:
                print("{0:<15}".format(s)),
            print("")
        print("")
        instructions = replaceLabels(instructions)
        print "Replaced"
        for p in instructions:
            for s in p:
                print("{0:<15}".format(s)),
            print("")
        print("")

        print ""
        print "Compiled:"
        for p in instructions:
            for s in p:
                print("{0:<15}".format(s)),
            print("")
        print("")
        
        for i in range(len(instructions)):
            memory[i] = "%.03i" % compileInstruction(instructions[i])

        assert len(memory) == 100
  


        with open(a+'.lmc', 'w+') as out:
            for line in memory:
                out.write(str(line) + '\n')



else:
    pass


