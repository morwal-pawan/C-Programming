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
int delete(struct node*);
FILE *fp;
void main()
{
int ch,v,tn=0;
root=NULL;
fp=fopen("input.txt","r");
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
fscanf(fp,"%d",&ch);
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
     search(root);
     break;
case 6:
     v=delete(root);
     printf("deleted node is:%d\n",v);
     break;
case 7:
     printf("total node is:%d",tn);
case 8:
     exit(0);

}
}while(1);
getch();
}
void insert()
{
struct node *p,*q;
 newnode=(struct node*)malloc(sizeof(struct node));
fscanf(fp,"%d",&newnode->info);
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
}
void search(struct node *ptr)
{
 struct node *p,*q;
 int val,flag=0;
 fscanf(fp,"%d",&val);
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
int delete(struct node *root)
{
 int val,n;
 struct node *p,*q,*pre,*ptr;
 fscanf(fp,"%d",&val);
 p=q=root;
 while(q!=NULL)
 {
  p=q;
  if(p->info==val)
  {
   pre=p;
   break;
  }
  else
 {
  if(p->info<val)
  {
    pre=q;
    q=q->right;
  }
  else
   {
    pre=q;
    q=q->left;
   }
 }
 }
 if(q->left==NULL&&q->right==NULL)
 {
   printf("node which you want to delete is a leaf node:\n");
   if(pre->info<q->info)
   {
    n=q->info;
    pre->right==NULL;
    free(q);
   }
   else
   {
    n=q->info;
    pre->left==NULL;
    free(q);
   }
 }
 return(n);
}

