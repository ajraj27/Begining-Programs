t=int(input())


while(t!=0):
	a,b,c=map(float,input().split())

	if(a>50 and b<0.7 and c>5600):
		pt=10

	elif(a>50 and b<0.7):
		pt=9

	elif(b<0.7 and c>5600):
		pt=8

	elif(a>50 and c>5600):
		pt=7

	elif(a>50 or b<0.7 or c>5600):
		pt=6

	else:
		pt=5					
		

	print(pt)		

	t=t-1			
