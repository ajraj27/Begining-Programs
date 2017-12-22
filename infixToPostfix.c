#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

struct Stack
{
	char item;
	struct Stack* next;
};

typedef struct Stack stack;
stack* top=NULL;

bool isoperator(char c)
{
	if (c=='+' || c=='-' || c=='*' || c=='/')
		return true;

	return false;
}

bool stackempty()
{
	if(top==NULL)
		return true;

	return false;
}

int getOpWeight(char op)
{
	int weight=-1;

	switch(op)
	{
		case '+':weight=1;break;
		case '-':weight=1;break;
		case '*':weight=2;break;
		case '/':weight=2;break;
	}
	return weight;
}

bool higherprecedance(char op1,char op2)
{
	int op1Weight=getOpWeight(op1);
	int op2Weight=getOpWeight(op2);

	return op1Weight>=op2Weight?true:false;
}

void Push(char ch){

	stack* temp=(stack*)malloc(sizeof(stack));

	temp->item=ch;
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
		printf("Stack Empty");

	else
		return top->item;
}

void infixToPostfix(char a[])
{
	char b[50];
	int i,k=-1;
	for(i=0;i<strlen(a);i++)
	{
		int num=a[i];
		if(isdigit(num))
			b[++k]=a[i];

		else if(isoperator(a[i]))
		{
			while(!stackempty() && higherprecedance(Top(),a[i]))
			{
				b[++k]=Top();
				Pop();

			}

			Push(a[i]);
		}

		else
		{
			printf("Invalid Input");
			break;}
	}


		while(!stackempty()){

				b[++k]=Top();
				Pop();}

				b[++k]='\0';

		printf("\nPostfix expression:%s",b)	;
}


int main()
{
	char a[50];

	printf("Enter the infix expression:");
	scanf("%s",a);

	infixToPostfix(a);

	return 0;
}