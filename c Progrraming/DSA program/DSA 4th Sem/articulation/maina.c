#include<stdio.h>
#include<sys/time.h>
#include"headera.h"
#define white 0
#define gray 1
#define black 2
#define max_node 1000
int main()
{
	int a,b,c,n,e,i,j,adj[max_node][max_node];
	FILE *fp;
	printf("\n FINDING ARTICULATION POINT \n");
	fp=fopen("articulation.text","r");
	if(fp==NULL)
		{
			printf("file error....\n");
			return;
		}
	fscanf(fp,"%d%d",&n,&e);
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
 articulation(n,e,adj);
   gettimeofday(&tim,NULL);
   timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
   executiontime=timeend-timestart;
   printf("\ntime taken in find articulation:%f\n",executiontime);
   printf("\n");
	return(0);
}
