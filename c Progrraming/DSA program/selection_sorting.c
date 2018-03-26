#include<stdio.h>
#define size 20
void selection_sort(int[],int n );
int main()
{
	int a[size],i,n;
	printf("enter the number of values to be sorted:");
	scanf("%d",&n);
	printf("enter the values in the array to sorted:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	struct timeval tim;
	double time_start,time_end;
	gettimeofday(&tim,NULL);
	time_start=(double)tim.tv_sec+(double)(tim.tv_usec/100000.0);
	selection_sort(a,n);
	time_end=(double)tim.tv_sec+(double)(tim.tv_usec/100000.0);
	printf("time tacken in selection sorting is:%f",time_end-time_start);
	printf("after the sorting the array is:\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	return(0);
}
void selection_sort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0&&temp<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
