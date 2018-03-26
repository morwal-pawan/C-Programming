#include<stdio.h>
#include<string.h>
#include"headerl.h"
int lcs()
{
	int i,j;
	char x[20],y[20];
	printf("enter the frist sequence:");
		gets(x);
	printf("enter the second secquence:");
		gets(y);
	printf("lcs are:\t");
	lcs_length(x,y);
	return 0;
}
int main()
{
	char ch;
	do
	{
		lcs();
		printf("\ncontinue(Y/N):");
		scanf("%c",&ch);
	}
	while(ch=='Y'||ch=='y');
	return 0;
}
