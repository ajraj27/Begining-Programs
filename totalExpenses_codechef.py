t=int(input())

while(t!=0):
	qty,price=map(float,input().split())

	if(qty>1000):
		print(format(qty*price-qty*price*0.1,'.6f'))

	else:
		print(format(qty*price,'.6f'))	

		
	t=t-1			
