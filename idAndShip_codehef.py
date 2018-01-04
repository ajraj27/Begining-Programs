t=int(input())

while(t!=0):
	comm=input()

	if(comm.lower()=='b'):
		print("BattleShip")	

	elif(comm.lower()=='c'):
		print("Cruiser")

	elif(comm.lower()=='d'):
		print("Destroyer")

	else:
		print("Frigate")				
		
	t=t-1			
