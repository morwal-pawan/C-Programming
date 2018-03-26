#include"header.h"
void quicksort(int a[],int lb,int ub)
{
	int q;
	if(lb<ub)
	{
		q=partitation(a,lb,ub);
		quicksort(a,q+1,ub);
		quicksort(a,lb,q-1);
	}
}
int partitation(int a[],int lb,int ub)
{
	int low,up,t,p;
	p=a[lb];
	low=lb;
	up=ub;
	do
	{
		while(low<up&&a[low]<p)
			low++;
		while(a[up]>p&&up>low)
			up--;
		if(low<up)
		{
			t=a[low];
			a[low]=a[up];
			a[up]=t;
		}
	}while(low<up);
	a[low]=a[up];
	a[up]=p;
	return(up);
}
