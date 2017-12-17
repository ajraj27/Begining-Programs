#include<stdio.h>
#include<string.h>

# define MAX_SIZE 101
int top=-1;
char stack[MAX_SIZE];

void push(char x)
{
	if(top==MAX_SIZE-1)
		printf("Stack Overflow\n");

	else
	{
		top=top+1;
		stack[top]=x;
	}	
}

void pop()
{


	if(top==-1)
		printf("Stack Underflow\n");

	else{
		printf("%c",stack[top]);
		top=top-1;
	}
}
int main()
{
	
	int i;
	char a[MAX_SIZE];

	printf("Enter the String:");
	scanf("%[^\n]",a);

	for(i=0;i<strlen(a);i++)
	{
		push(a[i]);

	}
	printf("Reversed string is:");

	for(i=0;i<strlen(a);i++)
	{
		pop();
	}

	return 0;
}