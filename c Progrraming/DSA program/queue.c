#include<stdio.h>
#include<stdlib.h>
#define n 10
int q[n];
void insert(int*,int*,int);
int delete(int*,int*);
int peek(int,int);
void main()
{
int front=-1,rear=-1,ch,val,j,temp;
do
{
 printf("1. for insert:\n");
 printf("2. for delete:\n");
 printf("3. for peep:\n");
 printf("4. for showlist:\n");
 printf("5. for exit:\n");
 printf("enter your choice...");
 scanf("%d",&ch);
switch(ch)
{
case 1:
    printf("enter the number to inserted:");
    scanf("%d",&val);
  insert(&front,&rear,val);
  break;
case 2:
    j=delete(&front,&rear);
    if(j==-1)
     printf("queue is empty:");
    else
     printf("deleted value is%d",j);
    break;
case 3:
     j=peep(front,rear);
     if(j==-1)
      printf("queue is empty:");
     else
      printf("peek value is%d",j);
    break;
case 4:
    temp=front;
    while(temp!=n-1)
     {
      printf("%d\n",q[temp]);
      temp++;
     }
     break;
case 5:
     exit(0);
 }
}while(1);
printf("you have done queue operation...");
}
void insert(int *front,int *rear,int val)
{
if(*front==0 && *rear==n-1 )
{
  printf("overflow");
  return;
}
if(*front==-1)
    *front=*rear=0;
else if(*rear==n-1)
    *rear=0;
  else
  {
    (*rear)++;
  }
  q[*rear]=val;
  }
int delete(int *front,int *rear)
{
 int j;
 if(*front==-1)
    return(-1);
 j=q[*front];
 if(*front==*rear)
    *front=*rear=-1;
 else if(*front==n-1)
    *front=0;
  else
    (*front)++;
  return(j);
}
int peep(int front,int rear)
{
if(front==-1)
    return(-1);
else
    return(q[front]);
}
