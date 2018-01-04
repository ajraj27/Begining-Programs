n=int(input())
count1=count2=0
a=list(map(int,input().split()))


for i in range(len(a)):

	if(a[i]%2==0):
		count1+=1

	else:
		count2+=1

if(count1>count2):
	print("READY FOR BATTLE")		
else:
	print("NOT READY")



