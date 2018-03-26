#include"headerl.h"
#include<stdio.h>
int print_lcs(char b[][20],char x[],int i,int j)
{
	if(i==0||j==0)
		return 0;
	if(b[i][j]=='c')
	{
		print_lcs(b,x,i-1,j-1);
		printf("%c\t",x[i-1]);
	}
	else if(b[i][j]=='u')
			print_lcs(b,x,i-1,j);
		else
			print_lcs(b,x,i,j-1);
}

