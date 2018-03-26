#include<stdio.h>
#include"headerr.h"
void create_heap(int list[],int n)
{
    int i,j,k,temp;
    for(k=2;k<=n;k++)
    {
        i=k;
        temp=list[k];
        j=i/2;
        while(i>1&&temp>list[j])
        {
            list[i]=list[j];
            i=j;
            j=i/2;
            if(j<1)
                j=1;
        }
        list[i]=temp;
    }
}

