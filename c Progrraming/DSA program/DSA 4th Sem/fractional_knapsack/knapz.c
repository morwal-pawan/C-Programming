#include<stdio.h>
#include"header.h"
int fraction_knapsack(int p[],int w[],int itm[],float pw[],int n,int m)
{
	float t1;
	int total=m,i,n1=n,t2,t3,t4;
	while(n1>0)
	{
		for(i=1;i<n;i++)
		{
			if(pw[i+1]>pw[i])
			{
				t1=pw[i+1];
				pw[i+1]=pw[i];
				pw[i]=t1;
			t2=p[i+1];
			p[i+1]=p[i];
			p[i]=t2;
				t3=w[i+1];
				w[i+1]=w[i];
				w[i]=t3;
			t4=itm[i+1];
			itm[i+1]=itm[i];
			itm[i]=t4;
			}
			
		}
		n1=n1-1;
	}
	for(i=1;i<=n;i++)
	{
		if(total>=w[i])
		{
			printf("item %d added to knapsack:\n",itm[i]);
			total=total-w[i];
		}
		else
		{
			if(total!=0)
			{
				printf("fraction of item %d added to knapsack:\n",itm[i]);
				total=total-(total/w[i]);
				break;
			}
		}
		printf("left capacity of knapsack is: %d\n",total);
	}
return 0;
}
