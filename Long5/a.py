import math

def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n <= 1:
        return False

    sqr = int(math.sqrt(n)) + 1

    for divisor in range(3, sqr, 2):
        if n % divisor == 0:
            return False
    return True


s=""
N=10**7
pc=0
file = open("prime.txt", "w")

for i in range (2,N):
    if is_prime(i):
        pc+=1
        file.write(str(i)+"\n")
        j=i
        while j>0:
            s=s+str(j%2)
            j//=2

file.close()

print("string length is",len(s))
print("ones count",s.count('1'))
print("total primes",pc)

# O(NlnN)