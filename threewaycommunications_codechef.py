import math

t=int(input())

while(t!=0):
	R=int(input())

	x1,y1=map(int,input().split())
	x2,y2=map(int,input().split())
	x3,y3=map(int,input().split())

	d1=math.sqrt((y2-y1)**2 + (x2-x1)**2)
	d2=math.sqrt((y3-y2)**2 + (x3-x2)**2)
	d3=math.sqrt((y3-y1)**2 + (x3-x1)**2)

	if((d1<=R and d2<=R) or (d2<=R and d3<=R) or (d1<=R and d3<=R)):
		print ("yes")

	else:
		print ("no")

	t=t-1	

