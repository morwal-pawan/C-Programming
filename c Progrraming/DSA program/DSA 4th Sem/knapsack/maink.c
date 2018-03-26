#include<stdio.h>
#include<sys/time.h>
#include"headerk.h"
#define size 10
int main()
{
	int p[size],w[size],i,n,m;
	printf("enter the number of the items:");
	scanf("%d",&n);
	printf("enter the maximum capicity of knapsack:");
	scanf("%d",&m);
	printf("enter the weights of all items:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("enter the profits of all items:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	printf("\n");
	printf("\t!!====knapsack problem is====!!");
	printf("\n-----------------------------------------\n");
	printf("item no: %d\n",n);
	printf("max capacity: %d\n",m);
	printf("\nitem no.: ");
	for(i=0;i<n;i++)
		printf("%d\t ",i+1);
	printf("\n---------------------------------------\n");
	printf("profit: ");
	for(i=1;i<=n;i++)
		printf("%d\t",p[i]);
	printf("\n---------------------------------------\n");
	printf("weights: ");
	for(i=1;i<=n;i++)
		printf("%d\t",w[i]);
	printf("\n");
	printf("-----------------------------------------\n");
	  struct timeval tim;
	    double timestart,timeend,executiontime;
	 gettimeofday(&tim,NULL);
	 timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
	knapsack(w,n,p,m);
	    gettimeofday(&tim,NULL);
	 timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
	 executiontime=timeend-timestart;
	 printf("\ntime in knapsack problem:%f\n",executiontime);
	return 0;
}
