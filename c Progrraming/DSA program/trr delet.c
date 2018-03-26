#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *left,*right;
};
struct node *root,*newnode;
void insert();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void search(struct node*);
int delete();
void main()
{
int ch,v,tn=0,x,val1;
root=NULL;
do
{
printf("1. for insert\n");
printf("2. for inorder\n");
printf("3. for preorder\n");
printf("4. for postorder\n");
printf("5. for search\n");
printf("6. for delete\n");
printf("7. for find total number of node:\n");
printf("8. for exit\n");
printf("enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
    insert();
    tn=tn+1;
    break;
case 2:
     inorder(root);
     break;
case 3:
     preorder(root);
     break;
case 4:
     postorder(root);
     break;
case 5:
     printf("enter the value to search:");
 scanf("%d",&x);
     search(x);
     break;
case 6:

     break;
case 7:
     printf("total node is:%d",tn);
case 8:
     exit(0);
default:
     printf("you enter wrong choice...");
}
}while(1);
getch();
}
void insert()
{
struct node *p,*q;
 newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the info:");
scanf("%d",&newnode->info);
newnode->left=NULL;
newnode->right=NULL;
if(root==NULL)
  root=newnode;
else
{
 p=q=root;
 while(q!=NULL)
 {
  p=q;
if(newnode->info==p->info)
 {
 printf("duplicate number...");
 return;
 }
else if(newnode->info<p->info)
    q=q->left;
     else
       q=q->right;
 }
if(newnode->info<p->info)
 p->left=newnode;
else
 p->right=newnode;
 }
}
void inorder(struct node *ptr)
{
if(ptr!=NULL)
{
inorder(ptr->left);
printf("%d\t",ptr->info);
inorder(ptr->right);
}
}
void preorder(struct node *ptr)
{
if(ptr!=NULL)
{
printf("%d\t",ptr->info);
preorder(ptr->left);
preorder(ptr->right);
}
}
void postorder(struct node *ptr)
{
if(ptr!=NULL)
{
postorder(ptr->left);
postorder(ptr->right);
printf("%d\t",ptr->info);
}
void search(struct node *ptr)
{
    int val;
 struct node *p,*q;
 int flag=0;
 printf("enter the value to search:");
 scanf("%d",&val);
 p=q=ptr;
 while(q!=NULL)
 {
  p=q;
  if(p->info==val)
  {
    flag++;
    break;
  }
  else
  {
   if(p->info<val)
    q=q->right;
    else
        q=q->left;
  }
 }
 if(flag==0)
    printf("value not found:\n");
 else
    printf("value found:\n");
}
