/*OPERATIONS ON CIRCULAR QUEUE*/
#include<stdio.h>
#include<stdlib.h>
#define size 20
int q[size]={0};
void insert(int*,int*,int);
int delete(int*,int*);
int peep(int,int);
int show(int*,int*);
int main()
{
	int front=-1,rear=-1;
	int n,ch;
  do
  {
	printf("1. for insert\n2. for delete\n3. for peep(front value)\n4. for show_value\n5. for exit:");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		printf("\nenter the value to insert:");
		scanf("%d",&n);
		insert(&front,&rear,n);
		printf("\nvalue inserted...\n");
		break;
	case 2:
		n=delete(&front,&rear);
		if(n==-1)
			printf("\nQueue is empty...\n");
		else
			printf("deleted value is:%d\n",n);
		break;
	case 3:
		n=peep(front,rear);
		if(n==-1)
			printf("\nQueue is empty...\n");
		else
			printf("front value in Queue is:%d\n",n);
		break;
	case 4:
		n=show(&front,&rear);
		if(n==-1)
			printf("\nQueue is empty...\n");
		break;
	case 5:
		exit(0);
	default:
		printf("\nwrong choice...\n");
	}
  }while(1);
  return 0;
}
void insert(int *front,int *rear,int n)
{
	if((*front==0 && *rear==size-1) || *front==*rear+1)	/*IN THIS CASE QUEUE IS FULL*/
		{
			printf("\nQueue is Full\n");
		}
	if(*front==-1)		/*INSERT FRIST ELEMENT IN QUEUE*/
			*front=*rear=0;
	
	else
	{
		if(*rear==size-1)	/*REAR AT LAST POSITION*/
		{
			*rear=0;
		}
		else
			(*rear)++;
	}
	q[*rear]=n;
}
int delete(int *front,int *rear)
{
	int n;
	if(*front==-1)	/*QUEUE IS EMPTY*/
		return(-1);
	n=q[*front];
	if(*front==*rear)	/*ONLY ONE ELEMENT LEFT IN QUEUE*/
		*front=*rear=-1;
	else
	{
		if(*front==size-1)	/*FRONT AT LAST POSITION*/
			*front = 0;
		else
			(*front)++;
	}
	return(n);
}
int peep(int front,int rear)
{
	if(front==-1)	/* IN THIS CASE QUEUE IS EMPTY*/
		return(-1);
	else
		return(q[front]);
}
int show(int *front,int *rear)
{
	printf("value in Queue is:");
	if(*front==-1)
		return(-1);
	else
		{
			while(*front!=*rear)
			{
				printf("%d\t",q[*front]);
				*front=*front+1;
		    }
		    printf("%d\n",q[*rear]);
		}
}
