# https://codeforces.com/problemsets/acmsguru/problem/99999/404
n, m = [int(x) for x in input().split()]
fortune=[]
for i in range(m):
    fortune.append(input())
print(fortune[(n%m)-1])
