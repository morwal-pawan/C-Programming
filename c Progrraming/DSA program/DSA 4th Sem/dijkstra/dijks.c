#include<stdio.h>
#include"headerd.h"
#define max_node 100
int dijkastra_algo(int n,int e,int s,int d,int distance[max_node],int cost[max_node][max_node])
{
	int i,u,v,count,w,flag[n],minimum,cost_node[n],total_cost=0;
	count=2;
	for(i=0;i<n;i++)
		flag[i]=0;
	flag[s]=1;
	printf("\n shortest path from source:( %d ) to destination:( %d )\n",s,d);
	while(s!=d)
	{
		minimum=999;
		for(w=0;w<n;w++)
		{
			if(cost[s][w]>0 && flag[w]==0)
			{
				if(distance[w]>(distance[s]+cost[s][w]))
				{
					distance[w]=distance[s]+cost[s][w];
				}
				if(distance[w]<minimum )
				{
					minimum=distance[w];
					total_cost=total_cost+distance[w];
					v=w;
					flag[w]=1;
				}
			}
		}
		printf("%d->%d\n",s,v);
		s=v;
	}
	printf("\n total cost for shortest path is:%d\n",total_cost);
	printf("\n cost for each nodes\n");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("node(%d):%d\n",i,distance[i]);
	}
}
