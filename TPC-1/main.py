def binPower(n, k):
    if k == 0:
        return 1
    else:
        if k % 2 == 0:
            return binPower(n*n, k/2)
        else:
            return n * binPower(n*n, k/2) 
        
def main():
    for i in range(1,10):
        print(binPower(1,i)+binPower(2,i)+binPower(3,i)+binPower(4,i))
        
if __name__ == "__main__":
    main()