#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include"headerk.h"
#define max_node 100 
int n,e,edge1[max_node],edge2[max_node],weight[max_node];
int main()
{
	int i,j,a,b,c;
	FILE *fp;
	printf("/n MINIMUM SPANING PROBLEM \n");
	fp=fopen("flow.text","r");
	if(fp==NULL)
	{
		printf(" file error...\n");
		exit(0);
	}
	fscanf(fp,"%d%d",&n,&e);
	for(i=0;i<e;i++)
	{
		fscanf(fp,"%d%d%d",&a,&b,&c);
		edge1[i]=a;
		edge2[i]=b;
		weight[i]=c;
	}
	printf("\n--------------------------------------\n");
	printf("Edges for minimum spaning tree...\n");
	struct timeval tim;
    double timestart,timeend,executiontime;
 	gettimeofday(&tim,NULL);
 	timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
	kruskals_algo(edge1,edge2,weight,n,e);
	gettimeofday(&tim,NULL);
   timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
   executiontime=timeend-timestart;
   printf("\ntime taken in kruskals algo problem:%f\n",executiontime);
   printf("\n");
	return 0;
}
