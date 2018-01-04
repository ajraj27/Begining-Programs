t=int(input())

while(t!=0):
	n=int(input())
	signal=input()

	if('I' in signal):
		print("INDIAN")

	elif('Y' in signal):
		print("NOT INDIAN")

	else:
		print("NOT SURE")	
		
	t=t-1			
