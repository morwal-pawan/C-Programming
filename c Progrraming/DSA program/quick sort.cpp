#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 20
int a[max];
void quicksort(int,int);
int partitation(int,int);
int main()
{
 int i,n;
 printf("enter the size of the array:");
 scanf("%d",&n);
 printf("enter the value in array:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 quicksort(0,n-1);
 printf("resultant array is:\n");
 for(i=0;i<n;i++)
  {
   printf("%d\n",a[i]);
  }
  printf("you have get your result...");
  getch();
}
void quicksort(int lb,int ub)
{
 int j;
 if(lb<ub)
 {
 j=partitation(lb,ub);
 quicksort(j+1,ub);
 quicksort(lb,j-1);
 }
}
int partitation(int lb,int ub)
{
int down,up,pivot,temp;
pivot=a[lb];
down=lb;
up=ub;
do
{
while(a[down]<=pivot&&down<=ub)
 down++;
while(a[up]>=pivot)
  up--;
if(down<up)
 {
 temp=a[down];
 a[down]=a[up];
 a[up]=temp;
 }
}while(down<=up);
a[lb]=a[up];
a[up]=pivot;
return(up);
}
