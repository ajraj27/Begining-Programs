n,t=map(int,input().split())


a=[list(map(int,input().split())) for i in range(n)]

while(t!=0):
    angle=int(input())
    count=angle//90
    rotated=a
    
    while(count!=0):    
        rotated=list(zip(*rotated[::-1]))
        count=count-1

    for i in range(n):
        for j in range(n):
            print(rotated[i][j],end=" ")
        print("\n")

    t=t-1   
