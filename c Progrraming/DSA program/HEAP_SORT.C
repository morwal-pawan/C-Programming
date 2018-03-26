#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void heap_sort(int*,int);
void create_heap(int*,int);
void display(int*,int);
FILE *fp;
int main()
{
    int a[100],i,size;
    fp=fopen("input.txt","r");
    fscanf(fp,"%d",&size);
    printf("you entered %d elements",size);
    for(i=1;i<=size;i++)
        fscanf(fp,"%d",&a[i]);
    create_heap(a,size);
    printf("\nheap is:");
    display(a,size);
    heap_sort(a,size);
    printf("soreted list is:");
    display(a,size);
  getch();
}
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
void display(int list[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d\t",list[i]);
    }
    printf("\n");
}
void heap_sort(int list[],int n)
{
    int i,j,k,temp,value;
    for(k=n;k>=2;--k)
    {
        temp=list[1];
        list[1]=list[k];
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
}
