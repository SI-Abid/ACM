for tc in range(int(input())):
    a, b = [int(x) for x in input().split()]
    if a%b==0:
        print(f'Case {tc+1}: divisible')
    else:
        print(f'Case {tc+1}: not divisible')