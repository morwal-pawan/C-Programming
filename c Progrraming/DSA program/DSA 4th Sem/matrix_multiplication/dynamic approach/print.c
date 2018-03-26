#include"headerm.h"
#include<stdio.h>
#define size 10
int print_seq(int s[size][size],int i,int j)
{
  abc:	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		print_seq(s,i,s[i][j]);
		print_seq(s,s[i][j]+1,j);
		printf(")");
	}
	printf("\n");
}
