#include<stdio.h>
#include"headerk.h"
#define size 10
int print_item(int v[][size],int w[],int i,int w1)
{
	int m;
	while(w1>0&&i>0)
	{
		if(v[i][w1]!=v[i-1][w1])
		{
			/*v[i][w1]=v[i-1][w1-w[i]];*/
			if(w1>=w[i])
			{
				w1=w1-w[i];
				printf("item %d added to knapsack:\n",i);
				i=i-1;
			}
			else
				w1=w1-w[i];
		}
		else
		{
			/*v[i][w1]=v[i-1][w1];*/
			i=i-1;	
		}
	}
return 0;
}
