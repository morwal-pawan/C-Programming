#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include"headerd.h"
#define max_node 100
int main()
{
	FILE *fp;
	int a,b,c,n,e,s,d,i,j,cost[max_node][max_node],distance[max_node];
	fp=fopen("dijkstra.text","r");
	if(fp==NULL)
	{
		printf("file opening error...\n");
		exit(0);
	}
	fscanf(fp,"%d%d%d%d",&n,&e,&s,&d);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cost[i][j]=0;
		}
		distance[i]=999;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%d%d%d",&a,&b,&c);
			cost[a][b]=c;
		}
	}
	distance[s]=0;
	struct timeval tim;
    double timestart,timeend,executiontime;
 	gettimeofday(&tim,NULL);
 	timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
  dijkastra_algo(n,e,s,d,distance,cost);
   	gettimeofday(&tim,NULL);
   	timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
   	executiontime=timeend-timestart;
   	printf("\ntime taken in dijkstra shortest path problem:%f\n",executiontime);
   	printf("\n");
	return 0;
}
