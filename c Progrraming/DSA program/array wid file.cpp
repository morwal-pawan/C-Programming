#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 20
int insert();
int remove();
void search();
void print();
FILE *fp;
int n,a[size]={0};
int main()
{

int i,v,l;
char ch;
fp=fopen("input.txt","r");
if(fp==NULL)
    printf("file does not exit:");
fscanf(fp,"%d",&n);
for(i=0;i<n;i++)
{
fscanf(fp,"%d",&a[i]);
}
do
{
fscanf(fp,"%c",&ch);
switch(ch)
{
case 'I':
      n=insert();
      break;
case 'D':
      n=remove();
      break;
case 'S':
      search();
      break;
case 'P':
      print();
      break;
case 'E':
      exit(0);
}
}while(1);
 getch();
}
int insert()
{
printf("you are in insert function:\n");
int i,j,val,pos;
fscanf(fp,"%d%d",&pos,&val);
for(i=n;i>=pos;i--)
{
a[i+1]=a[i];
}
a[pos]=val;
n=n+1;
printf("value inserted...\n");
return(n);
}
int remove()
{
int i,pos;
fscanf(fp,"%d",&pos);
for(i=pos;i<n;i++)
{
a[pos]=a[pos+1];
}
printf("value deleted...\n");
return(n);
}
void search()
{
int i,found=0,val;
fscanf(fp,"%d",&val);
for(i=0;i<n;i++)
{
if(a[i]==val)
{
 found=found+1;
 break;
}
}
if(found==0)
 printf("value not found:\n");
else
 printf("value found at position:%d=",i);
}
void print()
{
int j;
printf("value in array are:\n");
for(j=0;j<n;j++)
{
printf("%d\t",a[j]);
}
}
