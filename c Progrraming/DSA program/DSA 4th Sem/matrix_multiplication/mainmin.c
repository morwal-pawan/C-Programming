#include<stdio.h>
#include"headermin.h"
#define size 10
int main()
{
    int a[size];
    int n, i;
	printf("enter the number of matrixis:");
	scanf("%d",&n);
	printf("enter the size of all matrix:\n");
	for(i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);	
	}
    printf("Minimum number of multiplications is %d ", 
                          Matrix(a, 1, n));
	printf("\n");
    return 0;
}
