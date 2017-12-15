#include<stdio.h>

int i;

void check()
{
	i=40;
}
int main()
{
	i=30;
	check();
	printf("%d",i);
}
