#include<stdio.h>
#include<stdlib.h>
#include"header.h"
int main()
{
int i,j,n,*a,l,h;
	FILE *fp;
	fp=fopen("inputqrec.text","r");
	if(fp==NULL)
	{
		printf("file error....");
		return 0;
	}
	/*read inputs from the input file*/
	fscanf(fp,"%d",&n);
	a=(int*)malloc(sizeof(n));
	for(i=0;i<n;i++)
	{
	fscanf(fp,"%d",&a[i]);
	}
	/*calling merge sort function*/
	l=0;
	h=n-1;
	   struct timeval tim;
    double timestart,timeend,executiontime;
 gettimeofday(&tim,NULL);
 timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
    quicksort(a,l,h);
    gettimeofday(&tim,NULL);
 timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
 executiontime=timeend-timestart;
 printf("time in quick sort:%f=\n",executiontime);
printf("after the quick sorting numbers are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	
 gettimeofday(&tim,NULL);
 timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
    mergesort(a,l,h);
    gettimeofday(&tim,NULL);
 timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
 executiontime=timeend-timestart;
 printf("time in merge sort:%f\n",executiontime);
	printf("after merge sorting numbers are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	gettimeofday(&tim,NULL);
 timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
    quickSortIterative (a,l,h);
    gettimeofday(&tim,NULL);
 timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
 executiontime=timeend-timestart;
 printf("time in quick sort without recursion::%f\n",executiontime);
	gettimeofday(&tim,NULL);
 timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
    mergenon(a,l,h);
    gettimeofday(&tim,NULL);
 timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
 executiontime=timeend-timestart;
 printf("time in merge sort without recursion::%f\n",executiontime);
return 0;
}

