# https://codeforces.com/problemsets/acmsguru/problem/99999/123
# this is a code for the sum of the fibonacci series
n = int(input())
f1, f2, fn, s = 0, 1, 0, 1
if n==1:
    print(s)
else:
    for i in range(2,n+1):
        fn = f1 + f2
        s += fn
        f1 = f2
        f2 = fn
    print(s)
