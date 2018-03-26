#include<stdio.h>
#include<stdlib.h>
void insert(struct node*,struct node *ptr);
void remove(struct node*);
void search(struct node*);
void showlist(struct node*);
struct node
     {
      int info;
      struct node *link,*pre;
     };
      struct node *start,*newnode;
 int main()
 {
    struct node *ptr;
  int i,j,ch,n,n2;
  start=NULL;
  ptr=start;
  FILE *fp;
  fp=fopen("input.txt","r");
 fscanf(fp,"%d",&n);

for(i=0;i<n;i++)
 {
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
 {
  printf("overflow");
  exit(0);
 }
 newnode->link=NULL;
 fscanf(fp,"%d",&newnode->info);
 if(start==NULL)
 {
  start=newnode;
  ptr=newnode;
  }
 else
  {
  ptr->link=newnode;
  newnode->pre=ptr;
  ptr=ptr->link;
  }
 }
  do
  {
   printf("ENTER 1 FOR INSERT:\n");
    printf("ENTER 2 FOR DELETE:\n");
     printf("ENTER 3 FOR SEARCH:\n");
      printf("ENTER 4 FOR SHOELIST:\n");
       printf("ENTER 5 FOR EXIT:\n");
    printf("enter your choice...");
    scanf("%d",&ch);
 switch(ch)
 {
 case 1:
      insert(start,ptr);
      break;
 case 2:
      remove(start);
      break;
 case 3:
      search(start);
      break;
 case 4:
      showlist(start);
      break;
 case 5:
      exit(0);
 }
 printf("enter 0 for more operation:");
 scanf("%d",&n2);
  }while(n2==0);
 printf("you have done void main part:\n");
fclose(fp);
 }
 void insert(struct node *start,struct node *ptr)
 {
  newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode==NULL)
   {
   printf("overflow...");
   exit(0);
   }
   newnode->link=NULL;
  printf("enter the value to inserted:");
  scanf("%d",&newnode->info);
  if(start==NULL)
    {
     start=newnode;
     ptr=newnode;
    }
  else
   {
    ptr->link=newnode;
    newnode->pre=ptr;
    ptr=ptr->link;
   }
  printf("value inserted....");
 }
void remove(struct node *start)
{
 struct node *ptr;
 ptr=start;
while(ptr->link!=NULL)
 {
 ptr=ptr->link;
 }
 ptr->pre->link=NULL;
 ptr->pre=NULL;
 free(ptr);
printf("value deleted");
}
void search(struct node *start)
{
    struct node *ptr;
    ptr=start;
int n1,flag=0;
printf("enter the value to be search:");
scanf("%d",&n1);
while(ptr->link!=NULL)
 {
  if(ptr->info==n1)
   {
    flag=flag+1;
    break;
   }
  else
   {
    ptr=ptr->link;
   }
 }
if(flag==0)
 {
  printf("value not found\n");
 }
 else
   {
   printf("value found\n");
   }
}
void showlist(struct node *start)
{
struct node *ptr;
ptr=start;
printf("you entered in showlist function\n");

while(ptr->link!=NULL)
 {
  printf("%d\t",ptr->info);
  ptr=ptr->link;
 }
 printf("%d\n",ptr->info);
}
