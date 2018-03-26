#include<stdio.h>
#include"headers.h"
#define max_node 100
#define white 0
#define gray 1
#define black 2
int time,colour[max_node],time1[max_node],time2[max_node],sort[max_node],scc[max_node],k=0,k1;
int adj1[max_node][max_node],flag=0,t,finish[max_node];
int dfs_visit(int n,int adj[][max_node],int u)
{
	int i;
	time=time+1;
	time1[u]=time;
	colour[u]=gray;
	if(flag==2)
		finish[k++]=u;
	for(i=0;i<n;i++)
	{
		if(adj[u][i]==1 && colour[i]==white)
		{
			dfs_visit(n,adj,i);
			if(flag==1)
			{
				printf("%d->",i);
			}
		}
	}
	colour[u]=black;
	time=time+1;
	time2[u]=time;
}
int scc_graph(int n,int e,int adj[][max_node])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		flag=2;
		if(colour[i]==white)
		{
			dfs_visit(n,adj,i);
		}
	}
	printf("\n computing time for every node in given graph...\n");
	for(i=0;i<n;i++)
	{
		printf("node:(%d):\t%d/%d\n",i,time1[i],time2[i]);
	}
	for(i=0;i<n;i++)
	{
		if(colour[i]==white)
		{
			printf("\nGiven graph is itself a SCC graph...\n");
			break;
		}
	}
	printf("\n");
	for(i=1;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			adj1[i][j]=0;
			if(time2[j]<=time2[j+1])
			{
				t=time2[j];
				time2[j]=time2[j+1];
				time2[j+1]=t;
				k1=finish[j];
				finish[j]=finish[j+1];
				finish[j+1]=k1;
			}
		}
	}
/*Reversing graph...*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(adj[i][j]!=0)
			{
				adj1[j][i]=1;
			}
		}
		colour[i]=0;
	}
/*apply again dfs technique*/
	printf("\n scc graphs are...\n");
	printf("\n");
	for(j=0;j<n;j++)
	{
		i=finish[j];
		flag=1;
		if(colour[i]==0)
		{
			printf("%d->",i);
			dfs_visit(n,adj1,i);
		}
		printf("\n");
	}
	time=0;
	for(i=0;i<n;i++)
	{
		colour[i]=0;
		time1[i]=0;
		time2[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(colour[i]==white)
		{
			dfs_visit(n,adj1,i);
		}
	}
	printf("\n computing time for every node in transpose graph...\n");
	for(i=0;i<n;i++)
	{
		printf("node:(%d):\t%d/%d\n",i,time1[i],time2[i]);
	}
}
