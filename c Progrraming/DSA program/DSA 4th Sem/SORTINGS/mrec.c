#include"header.h"
void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,mid+1,high);
	}
}
void merge(int a[],int low1,int high1,int low2,int high2)
{
	int i,j,k=0,temp[10];
	i=low1;
	j=low2;
	while(i<high1&&j<high2)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<high1)
		temp[k++]=a[i++];
	while(j<high1)
		temp[k++]=a[j++];
	for(i=0;i<k;i++)
	{
		a[i]=temp[i];
	}
}
