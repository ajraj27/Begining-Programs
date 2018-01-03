t=int(input())
a=[1,2,4,8,16,32,64,128,256,512,1024,2048]

while(t!=0):
    n=int(input())
    count=0
    res=0

    for i in range(len(a)):

        if(n>2048):
            ind=11
            break

        if(a[i]==n):
            res=1
            print(res)
            break

        if(a[i]>n):
            ind=i-1
            break   

    if(res!=1):
        i=ind
        while(n%a[i]!=0):
            count=count+n//a[i]
            n=n%a[i]
            i=i-1

        count=count+n//a[i]        
        print(count)        

    t=t-1        
           



