#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct Stack
{
	int item;
	struct Stack* next;
};

typedef struct Stack stack;
stack* top=NULL;

bool isoperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return true;

	return false;
}

int evaluate(char c,int num1,int num2)
{
	if(c=='+')
		return num1+num2;
	else if(c=='-')
		return num1-num2;
	else if(c=='*')
		return num1*num2;
	else if(c=='/')
		return num1/num2;
	else
		return -1;
}

void push(int num)
{
	stack* temp=(stack*)malloc(sizeof(stack));

	temp->item=num;
	temp->next=top;
	top=temp;
}

void Pop()
{
	stack* temp=top;
	top=top->next;
	free(temp);
}

char Top()
{
	if(top==NULL)
		printf("\nStack Empty");

	else
		return top->item;
}

int evaluatePostfix(char a[])
{
	for(int i=0;i<strlen(a);i++)
	{
		int numb=a[i];
		if(isdigit(numb)){
			int num=a[i]-'0';
			push(num);
		}


		else if(isoperator(a[i]))
		{
			int num2=Top();
			Pop();
			int  num1=Top();
			Pop();

			int result=evaluate(a[i],num1,num2);

			push(result);

		}
		else
			printf("\nIncompatible Input");

	}

	return Top();
}

int main()
{

	char a[50];

	printf("Enter the postfix expression:");
	scanf("%s",a);

	int res=evaluatePostfix(a);

	printf("\nAnswer is:%d",res);

	return 0;
}
