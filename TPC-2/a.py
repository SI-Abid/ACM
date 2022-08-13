import math


tc = 1
while True:
    try:
        #read a line
        line = input()
        #split the line into words
        a, b = [int(x) for x in line.split(':')]
        rat = a/b
        w = 400/((math.pi)+2*rat)
        l = w*rat 
        print(f"Case {tc}: {l:.6f} {w:.6f}")
        tc += 1
    except EOFError:
        break