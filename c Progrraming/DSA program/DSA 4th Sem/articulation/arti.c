#include<stdio.h>
#include"headera.h"
#define white 0
#define gray 1
#define black 2
int visited[max_node];
int articulation(int n,int e,int adj[][max_node])
{
	int i,j,ch,adj2[max_node][max_node];
	ch=0;
	while(ch<n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				adj2[i][j]=adj[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			visited[i]=0;
		}
		visited[ch]=1;
		for(j=0;j<n;j++)
		{	
			adj2[ch][j]=0;
		}
		bfs(0,n,adj2,adj,ch);
		ch++;
	}
}

