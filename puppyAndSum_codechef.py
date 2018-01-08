
def sum(d,n):


	if(d==0):
		return n

	else:
		add=n*(n+1)//2
		return sum(d-1,add)
			


t=int(input())

while(t!=0):
	d,n=map(int,input().split())

	res=sum(d,n)

	print(res)		

	t=t-1			
