#include<stdio.h>
#include"headerm.h"
#define size 10
int main()
{
	int i,n,m,a[size];
	printf("enter the number of matrix:");
	scanf("%d",&n);
	printf("enter element the matrixes:");
	for(i=0;i<=n;i++)
		scanf("%d",&a[i]);
	m=matrix_mult(a,n+1);
	printf("minimum nuber of multipication:%d",m);
	printf("\n");
	return 0;
	
}
