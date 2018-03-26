#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};
struct node *newnode,*top,*ptr;
void push();
int pop();
void disple();
FILE *fp;
int main()
{
top=NULL;
int i,n;
char ch;

fp=fopen("input.txt","r");
if(fp==NULL)
printf("file does not exit:\n");
fscanf(fp,"%d",&n);
for(i=0;i<n;i++)
{
  newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode==NULL)
   {
    printf("overflow");
    break;
   }
fscanf(fp,"%d",&newnode->info);
newnode->link=NULL;
if(top==NULL)
  {
   top=newnode;
   ptr=newnode;
  }
else
 {
  top->link=newnode;
  top=newnode;
 }

}
do
{
fscanf(fp,"%c",&ch);
switch(ch)
{
case 'P':
       push();
       break;
case 'O':
       n=pop();
      if(n==-1)
     printf("stack is empty:\n");
    else
     printf("value deleted is:%d\n",n);
       break;
case 'D':
       disple();
       break;
case 'E':
       exit(0);
}
}while(1);
getch();
}
void push()
{
int n;
newnode=(struct node*)malloc(sizeof(struct node));
fscanf(fp,"%d",&newnode->info);
newnode->link=NULL;
if(top==NULL)
{
 top=newnode;
}
else
{
top->link=newnode;
top=newnode;
}
printf("value pushed is %d:\n",newnode->info);
}
int pop()
{
int n;
struct node *temp,*pre;
temp=ptr;
if(top==NULL)
return(-1);
while(temp=NULL)
{
 pre=temp;
 temp=temp->link;
}
n=temp->info;
pre->link=temp->link;
free(temp);
return(n);
}
void disple()
{
struct node *temp;
temp=ptr;
while(temp!=NULL)
{
printf("%d\n",temp->info);
temp=temp->link;
}
}
