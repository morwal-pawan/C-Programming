#include<stdio.h>
#include"headerb.h"
#define max_node 100
int bellman_ford(int n,int e,int s,int node_dist[max_node],int edge_dist[][max_node])
{
	int i,j,ch=0;
	while(ch<n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((node_dist[j]>node_dist[i]+edge_dist[i][j]) && edge_dist[i][j]!=0)
				{
					node_dist[j]=node_dist[i]+edge_dist[i][j];
				}
			}
		}
		ch++;
	}
	for(i=0;i<n;i++)
	{
		printf("node:(%d)>>( shortest distacne ):%d\n",i,node_dist[i]);
	}
}
