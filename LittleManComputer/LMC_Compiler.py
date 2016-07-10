
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


memory = ["NULL"] * 100
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
        if (len(instructions[i]) == 1 or 
            (len(instructions[i]) == 2 and 
            any( op in instructions[i] for op in ops))):
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



def compileInstruction(instruction, line):
    '''
    [LABEL] [OP] [Mailbox/Value]
    MYLABEL DAT 444
    DAT 444
    LOOP BRZ END
    END HLT
    '''
    assert len(instruction) <= 3 
    assert instruction[0].isalpha() 
   

    parts = len(instruction)

    #make all lowercase
    ins = instruction[:]
    print ins
    for i in range(len(ins)):
        ins[i] = ins[i].lower()
    print ins
    
    if ins[0] == 'inp' or ins[0] == 'input' or ins[0] == 'hlt' or ins[0] == 'halt':
        ins += [0]
        parts += 1
    ''' 
    op = ins[-1]
    if parts < 3 and (op == 'dat' or op == 'data'):
        ins += [0]
        parts += 1

    
    op = ins[0]
    if parts == 1 and (op == 'hlt' or op == 'halt'):
        ins += [0]
        parts += 1
    '''

    op = None
    box = None
    label = None
    try:
        if parts == 2: #nolabel   [op] [box]
            label = None
            op = ins[0].lower()
            box = ins[1]
        
            if isinstance(box, int):
                return opCodes[op] + box
            else:
                return opCodes[op] + labels[box.lower()]
        elif parts == 3:  #label      [new label] [op] [box|toLabel]
            label = ins[0].lower()
            op = ins[1].lower()
            box = int(ins[2])


            labels[label] = line
            
            if opCodes[op] == None:
                return box
            
            return opCodes[op] + box
        

        else:
            pass
        
    except KeyError:
           print "Label not defined " 
           print repr(labels), label, op, box, "|", parts
           return "ERR"




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
        print ""
        instructions = fixInstructions(instructions)
        print instructions
        print ""
        instructions = replaceLabels(instructions)
        for p in instructions:
            print(p)
        print ""
        
        #instructions = compileInstructions(instructions)




        with open(a+'.lmc', 'w+') as out:
            for line in memory:
                out.write(str(line) + '\n')



else:
    pass


