#include<stdio.h>
#include"headera.h"
#define white 0
#define gray 1
#define black 2
int q[max_node+2],head=0,tail=0,visited[max_node];
int bfs(int s,int n,int adj[][max_node],int adj2[][max_node],int ch)
{
	int v,u,i,j;
	if(ch!=0)
		enqueue(s);
	else
		{
			for(i=0;i<n;i++)
			{
				if(adj2[ch][i]>0)
				{
					enqueue(i);
					break;
				}
			}
		}
	while(head!=tail)
	{
		u=dequeue();
		for(v=0;v<n;v++)
		{
			if(visited[v]==white && adj[u][v]>0)
			{
				enqueue(v);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("\narticulation point is node: %d\n",ch);
			break;
		}
	}
	head=tail=0;
	for(i=0;i<max_node;i++)
	{
		q[i]=-1;
	}
}
int enqueue(int x)
{
	q[tail++]=x;
	visited[x]=gray;
}
int dequeue()
{
	int x;
	x=q[head];
	head++;
	return(x);
}

