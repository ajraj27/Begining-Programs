t=int(input())

while(t!=0):
    n=int(input())
    small=list(map(int,input().split()))
    small.sort()
    print(small[0]+small[1])
    t=t-1