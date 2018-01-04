t=int(input())

def hcf(a,b):

	if(a>=b):

		if(b==0):
			return a
		else:
			return hcf(b,a%b)

	else:
	
		if(a==0):
			return b
		else:
			return hcf(a,b%a)				

while(t!=0):
	a,b=map(int,input().split())

	gcd=hcf(a,b)
	lcm=(a*b)//gcd
	print(gcd,lcm)

	t=t-1			
