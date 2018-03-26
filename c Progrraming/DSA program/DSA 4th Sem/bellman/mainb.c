#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include"headerb.h"
#define max_node 100
int main()
{
	FILE *fp;
	int a,b,c,n,e,s,i,j,node_dist[max_node],edge_dist[max_node][max_node];
	fp=fopen("bellman1.text","r");
	if(fp==NULL)
	{
		printf("file opening error...\n");
		exit(0);
	}
	printf("\n BELLMAN FORD PROBLEM \n");
	printf("\n----------------------------------\n");
	fscanf(fp,"%d%d%d",&n,&e,&s);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			edge_dist[i][j]=0;
		}
		node_dist[i]=999;
	}
	node_dist[s]=0;
	for(i=0;i<e;i++)
	{
		fscanf(fp,"%d%d%d",&a,&b,&c);
		edge_dist[a][b]=c;
	}
	struct timeval tim;
    double timestart,timeend,executiontime;
 	gettimeofday(&tim,NULL);
 	timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
  bellman_ford(n,e,s,node_dist,edge_dist);
   	gettimeofday(&tim,NULL);
   	timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
   	executiontime=timeend-timestart;
   	printf("\ntime taken in bellman ford problem:%f\n",executiontime);
   	printf("\n");
	return(0);
}

