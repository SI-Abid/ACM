mem = [0,0,0,1,1,1,2,2,3,3]

for i in range(10,300009):
    mem.append(mem[i-2] + mem[i-3] + mem[i-4] - mem[i-5] - mem[i-6] - mem[i-7] + mem[i-9])

for _ in range(int(input())):
    x = int(input())
    print(mem[x])