#include"header.h"
#include<stdio.h>
void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int l, int h)
{
    int j,x = arr[h];
    int i = (l - 1);
 
    for (j=l;j<=h-1;j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
void quickSortIterative (int arr[], int l, int h)
{
	int n,i;
	
    int stack[ h - l + 1 ];
    int top = -1;
    stack[ ++top ] = l;
    stack[ ++top ] = h;
    while ( top >= 0 )
    {
        h = stack[ top-- ];
        l = stack[ top-- ];
           int p = partition( arr, l, h );
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
	printf("quick sorting without recursion....\n"); 
    for (i=0;i<5;i++)
        printf("%d\t",arr[i]);
printf("\n");
}

