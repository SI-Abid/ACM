# https://codeforces.com/problemsets/acmsguru/problem/99999/460
case1 = ['x','s','o']
n=int(input())
for i in range(n):
    s = input()
    if s[-1] in case1:
        print(s+'es')
    elif s[-1] == 'h' and s[len(s)-2]=='c':
        print(s+'es')
    elif s[-1] == 'f':
        s = s[:len(s) - 1]
        print(s+'ves')
    elif s[-1] == 'e' and s[len(s)-2]=='f':
        s = s[:len(s) - 2]
        print(s+'ves')
    elif s[-1] == 'y':
        s = s[:len(s) - 1]
        print(s+'ies')
    else:
        print(s+'s')
