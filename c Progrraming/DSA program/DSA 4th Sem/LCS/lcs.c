#include"headerl.h"
#include<stdio.h>
#include<string.h>
void lcs_length(char x[],char y[])
{
	int m,n,i,j,c[20][20];
	char b[20][20];
	m=strlen(x);
	n=strlen(y);
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(i=0;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='c';
			}
			else if(c[i-1][j]>c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					b[i][j]='u';
				}
				else
				{
					c[i][j]=c[i][j-1];
					b[i][j]='l';
				}
		}
		print_lcs(b,x,m,n);
}

