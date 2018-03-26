#include<stdio.h>
#include<stdlib.h>
#include"headerp.h"
#include<sys/time.h>
#define max_node 100 
int main()
{
	int i,j,a,b,c;
	int n,e,weight[max_node][max_node];
	FILE *fp;
	printf("/n MINIMUM SPANING PROBLEM < prims algorith > \n");
	fp=fopen("flow.text","r");
	if(fp==NULL)
	{
		printf(" file error...\n");
		exit(0);
	}
	fscanf(fp,"%d%d",&n,&e);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			weight[i][j]=999;
		}
	}
	for(i=0;i<e;i++)
	{
		fscanf(fp,"%d%d%d",&a,&b,&c);
		weight[a][b]=c;
		weight[b][a]=c;
	}
	printf("\n--------------------------------------\n");
	printf("Edges for minimum spaning tree...\n");
	struct timeval tim;
    double timestart,timeend,executiontime;
 	gettimeofday(&tim,NULL);
 	timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
  prims_algo(n,e,weight);
	gettimeofday(&tim,NULL);
   	timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
   	executiontime=timeend-timestart;
   	printf("\ntime taken in prims algo problem:%f\n",executiontime);
   	printf("\n");
	return 0;
}
