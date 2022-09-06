for _ in range(int(input())):
    n=int(input())
    ans = (n//7) * 9
    rem = n%7
    ans += rem
    if rem>=5:
        ans+=2
    if rem==4:
        ans+=1
    print(ans)