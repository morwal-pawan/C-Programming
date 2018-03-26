#include<stdio.h>
#include<stdlib.h>
#include"headert.h"
#define max_node 100
int main()
{
	FILE *fp;
	int i,j,n,e,a,b,c,s,adj[max_node][max_node],pred[max_node];
	fp=fopen("graph.text","r");
	if(fp==NULL)
	{
		printf("file opening error...\n");
		exit(0);
	}
	fscanf(fp,"%d%d%d",&n,&e,&s);   /* s is the starting node */
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			adj[i][j]=0;
		}
	}
	for(i=0;i<e;i++)
	{
		fscanf(fp,"%d%d%d",&a,&b,&c);
		adj[a][b]=c;
	}
	struct timeval tim;
    double timestart,timeend,executiontime;
 	gettimeofday(&tim,NULL);
 	timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
  topological_sorting(n,e,adj);
	gettimeofday(&tim,NULL);
   	timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
   	executiontime=timeend-timestart;
   	printf("\ntime taken in kruskals algo problem:%f\n",executiontime);
   	printf("\n");
	return(0);
}
	

