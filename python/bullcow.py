# https://codeforces.com/problemsets/acmsguru/problem/99999/486
secret = input()
guess = input()
bull, cow = 0, 0
for i in secret:
    if i in guess:
        if secret.index(i)==guess.index(i):
            bull+=1
        else:
            cow+=1
print(bull, cow)
