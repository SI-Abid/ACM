# https://codeforces.com/problemsets/acmsguru/problem/99999/102
def gcd(a, b):
    if b ==0:
        return a
    else:
        return gcd(b, a%b)

n = int(input())
count=0
for i in range(1,n+1):
    if gcd(n,i)==1:
        count+=1
print(count)
