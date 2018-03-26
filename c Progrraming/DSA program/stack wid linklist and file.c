#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};
struct node *newnode;
void push(struct node*,struct node*);
int pop(struct node*,struct node*);
void disple(struct node*);
FILE *fp;
int main()
{
struct node *top,*ptr;
int i,n;
char ch;
top=NULL;
fp=fopen("inputt.txt","r");
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
       push(top,ptr);
       break;
case 'O':
       n=pop(top,ptr);
      if(n==-1)
     printf("stack is empty:\n");
    else
     printf("value deleted is:%d\n",n);
       break;
case 'D':
       disple(ptr);
       break;
case 'E':
       exit(0);
}
}while(1);
getch();
}
void push(struct node *top,struct node *ptr)
{
int n;
newnode=(struct node*)malloc(sizeof(struct node));
fscanf(fp,"%d",&newnode->info);
newnode->link=NULL;
if(ptr==NULL)
{
top=newnode;
ptr=newnode;
}
else
{
top->link=newnode;
top=newnode;
}
printf("value pushed:\n");
}
int pop(struct node *top,struct node *ptr)
{
int n;
struct node *temp,*pre;
temp=ptr;
if(top==NULL)
return(-1);
while(temp->link!=NULL)
{
 pre=temp;
 temp=temp->link;
}
n=temp->info;
pre->link=temp->link;
free(temp);
return(n);
}
void disple(struct node *ptr)
{
struct node *temp;
temp=ptr;
while(temp!=NULL)
{
printf("%d\n",temp->info);
temp=temp->link;
}
}
