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
int count_leaf_node(struct node*);
int count_internal_node(struct node*);
int count_total_nodes(struct node*);
void main()
{
int ch,l,i,k;
root=NULL;
do
{
printf("\n1. for insert\n");
printf("2. for inorder\n");
printf("3. for preorder\n");
printf("4. for postorder\n");
printf("5. for search\n");
printf("6.for count leaf node\n");
printf("7.for count internal nodes node\n");
printf("8. for count total no. of nodes\n");
printf("9. for exit\n");
printf("enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
    insert();
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
     l=count_leaf_node(root);
     printf("total leaf nodes are ::%d",l);
     break;
case 7:
     i=count_internal_node(root);
     printf("total internal nodes are ::%d",i);
     break;
case 8:
    k=count_total_node(root);
    printf("total no of nodes are%d",k);
case 9:
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
}
void search(struct node *ptr)
{
 struct node *p,*q;
 int val,flag=0;
 printf("enter the value to be search:");
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
int count_leaf_node(struct node *node)
{
    if(node==NULL)
        return(0);
    else
        if(node->left==NULL&&node->right==NULL)
        {
         return(1);
        }
        else
        {
            return(count_leaf_node(node->left)+count_leaf_node(node->right));
        }
}
int count_internal_node(struct node *node)
{
    if(node==NULL)
        return(0);
    else if((node->left!=NULL||node->right!=NULL)||((node->left==NULL&&node->right!=NULL)||(node->right==NULL&&node->left!=NULL)))
        {
         return(1+count_internal_node(node->left)+count_internal_node(node->right));
        }
        else
            return(0);
}
int count_total_node(struct node *ptr)
{
     int a,b;
    a=count_leaf_node(ptr);
    b=count_internal_node(ptr);
   if(ptr==NULL)
    return(0);
   else
    return(a+b);
}
