#include<stdio.h>
#include"headerp.h"
#define max_node 100
int prims_algo(int n,int e,int weight[][max_node])
{
	int i,j,min,minimum_cost=0,ne=1,a,b,u,v;
	int visited[max_node];
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	visited[0]=1;
	while(ne<n)
	{
		for(i=0;i<n;i++)
		{
			min=999;
			for(j=0;j<n;j++)
			{
				if(weight[i][j]<min && visited[i]==0)
				{
					min=weight[i][j];
					a=u=i;
					b=v=j;
					if((visited[u]==0 || visited[v]==0) && min!=999)
					{
						printf("\n %d->%d",a,b);
						minimum_cost+=min;
						visited[b]=1;
					}
					weight[a][b]=weight[b][a]=999;
				}
			}
		}
		ne++;
	}
	printf("\nminimum cost: %d\n",minimum_cost);
}
