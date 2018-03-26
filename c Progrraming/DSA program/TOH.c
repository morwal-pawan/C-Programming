#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int toh(int,char,char,char);
void main()
{
int n;
char beg,aux,end;
beg='A';
aux='B';
end='C';
printf("enter the number of disk:");
scanf("%d",&n);
toh(n,beg,aux,end);
getch();
}
int toh(int n,char beg,char aux,char end)
{

if(n==1)
{
printf("moved disk 1 from %c to %c \n",beg,end);
return(0);
}
toh(n-1,beg,end,aux);
printf("moved disk %d from %c to %c \n:",n,beg,end);
toh(n-1,aux,beg,end);
return(0);
}
