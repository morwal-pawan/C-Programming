#include<stdio.h>
#include"headert.h"
#define max_node 100
#define white 0
#define gray 1
#define black 2
int time,colour[max_node],time1[max_node],time2[max_node],sort[max_node],k=0;
int dfs_visit(int n,int adj[][max_node],int u)
{
	int i;
	time=time+1;
	time1[u]=time;
	colour[u]=gray;
	for(i=0;i<n;i++)
	{
		if(adj[u][i]>0 && colour[i]==white)
		{ 
			dfs_visit(n,adj,i);
			sort[k++]=i;
		}
	}
	colour[u]=black;
	time=time+1;
	time2[u]=time;
}
int topological_sorting(int n,int e,int adj[][max_node])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		colour[i]=white;
	}
	time=0;
	for(i=0;i<n;i++)
	{
		if(colour[i]==white)
		{
			dfs_visit(n,adj,i);
			sort[k++]=i;
		}
	}
	printf("\ntopological order is....\n");
	printf("\n");
	for(i=k-1;i>=0;i--)
	{
		printf("%d->",sort[i]);
	}
	printf("\n");
	printf("\n finishing time for each vertex...\n");
	printf("\n");
	for(i=0;i<n;i++)
		printf("node:(%d):%d/%d\n",i,time1[i],time2[i]);
	printf("\n");
}

