#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct bal_paranthesis
{
	char x;
	struct bal_paranthesis* next;
};

typedef struct  bal_paranthesis node;
node* top=NULL;

void Push(char ch){

	node* temp=(node*)malloc(sizeof(node));

	temp->x=ch;
	temp->next=top;
	top=temp;
}

void Pop()
{
	node* temp=top;
	top=top->next;
	free(temp);
}

char Top()
{
		return top->x;
}


bool ArePair(char open,char close)
{
	if((open=='(' && close==')') ||( open=='[' && close==']' )||( open=='{' && close=='}'))
		return true;
	else
		return false;
}



 bool checkBalancedParantheis(char a[])
{
	int l=strlen(a);

	for(int i=0;i<l;i++){
	
		if(a[i]=='(' || a[i]=='{' || a[i]=='[')
			Push(a[i]);
	

	else if(a[i]==')' || a[i]=='}' || a[i]==']')
	{
		
		if(top==NULL || !ArePair(Top(),a[i])  )
			return false;

		else
			Pop();
	}

	}


	return top==NULL?true:false;
}



int main()
{
	char a[40];
	printf("Enter the string of paranthesis:");
	scanf("%s",a);

	bool d=checkBalancedParantheis(a);

	printf("\n%s",d?"true":"false");

	return 0;
}	
	