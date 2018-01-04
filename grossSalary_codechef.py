t=int(input())


while(t!=0):
	basic_salary=int(input())

	if(basic_salary>=1500):
		gross_salary=basic_salary*1.98+500

	else:
		gross_salary=float(basic_salary*2)
		

	print(gross_salary)		

	t=t-1			
