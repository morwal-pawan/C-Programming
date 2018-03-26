#include<stdio.h>
#include"headerr.h"
void heap_sort(int list[],int n)
{
    int i,j,k,temp,value;
    for(k=n;k>=2;--k)
    {
        temp=list[1];
        list[1]=value;
        list[k]=temp;
        i=1;
        value=list[1];
        j=2;
        if(j+1<k)
            if(list[j+1]>list[j])
                j++;
        while((j<=(k-1))&&(list[j]>value))
        {
            list[i]=list[j];
            i=j;
            j=2*i;
            if((j+1)<k)
                if((list[j+1]>list[j]))
                    j++;
                else if(j>n)
                    j=n;
                list[i]=value;
      }
    }
for(i=1;i<=n;i++)
    {
        printf("%d\t",list[i]);
    }
}
