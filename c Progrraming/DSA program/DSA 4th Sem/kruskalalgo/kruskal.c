#include<stdio.h>
#include"headerk.h"
int kruskals_algo(int edge1[],int edge2[],int weight[],int n,int e)
{
	int i,j,t1,t2,t3,make_set[n],total_weight=0;
	for(i=0;i<n;i++)
		make_set[i]=i+1;
	for(i=0;i<e-1;i++)
	{
		for(j=i;j>=0;j--)
		{
			if(weight[j]>=weight[j+1])
			{
				t1=weight[j];
				weight[j]=weight[j+1];
				weight[j+1]=t1;
				t2=edge1[j];
				edge1[j]=edge1[j+1];
				edge1[j+1]=t2;
				t3=edge2[j];
				edge2[j]=edge2[j+1];
				edge2[j+1]=t3;
			}
		}
	}
	for(i=0;i<e;i++)
	{
		if(make_set[edge1[i]]!=make_set[edge2[i]])
		{
			for(j=0;j<i;j++)
			{
				make_set[edge1[j]]=make_set[edge2[j]]=100;
			}
			total_weight+=weight[i];
			printf("edge: %d-%d\n",edge1[i],edge2[i]);
		}
	}
	printf("\ntotal weight of spaning tree: %d\n",total_weight);
}
