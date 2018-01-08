t=int(input())


while(t!=0):
	str1=input()
	str2=input()
	choice='Yes'

	for i in range(len(str1)):

		if(str1[i]=='?' or str2[i]=='?'):
			continue

		if(str1[i]!=str2[i]):
			choice='No'
			break				


	print(choice)		

	t=t-1			
