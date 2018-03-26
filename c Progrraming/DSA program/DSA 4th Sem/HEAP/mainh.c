#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include"headerr.h"
FILE *fp;
int main()
{
    int a[100],i,size;
    fp=fopen("inputqrec.text","r");
    fscanf(fp,"%d",&size);
    printf("you entered %d elements\n",size);
    for(i=1;i<=size;i++)
        fscanf(fp,"%d",&a[i]);
	printf("heap is:");
	create_heap(a,size);
	display(a,size);
printf("sorted values:");
    struct timeval tim;
    double timestart,timeend,executiontime;
 gettimeofday(&tim,NULL);
 timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
    heap_sort(a,size);
    gettimeofday(&tim,NULL);
 timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
 executiontime=timeend-timestart;
 printf("\ntime in heap sort:%f\n",executiontime);
 	return 0;
}

