#include<stdio.h>
#include"headerk.h"
int knapsack(int w[],int n,int p[],int w1)
{
	/*w1=maximum capicity
		w2 weight */
	int v[n][w1],i,w2;
	for(i=0;i<=n;i++)
		v[i][0]=0;
	for(w2=0;w2<=w1;w2++)
		v[0][w2]=0;
	for(i=1;i<=n;i++)
	{
		for(w2=1;w2<=w1;w2++)
		{
			if(w[i]<=w1)
				if((p[i]+v[i-1][w1-w[i]])>v[i-1][w2])
					v[i][w2]=p[i]+v[i-1][w1-w[i]];
				else
					v[i][w2]=v[i-1][w2];
			else 
				v[i][w2]=v[i-1][w2];
		}
	}
for(i=0;i<=n;i++)
	{
		for(w2=0;w2<=w1;w2++)
		{
			printf("%d\t",v[i][w2]);
		}
		printf("\n");
	}
	print_item(v,w,n,w1);
return 0;
}

