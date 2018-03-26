#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct{
    int n;
    char source;
    char spare;
    char dest;
    int flag;
}stack;

stack a[100];
int top=0;

void push(int num,char src,char dest,char spare,int flag){
    a[top].n=num;
    a[top].source=src;
    a[top].dest=dest;
    a[top].spare=spare;
    a[top].flag=flag;
    top++;   
}
stack pop(){   
    if(top==0)
        printf("\nStack is empty\n");
    else
    {
        top--;
        return a[top];
    }
}

int power(int base,int n){
    int i,val;
    val=1;
    for(i=1;i<=n;++i)
        val=val*base;
    return val;

}

void nontoh(int num,char src,char dest,char spare)
{
    int i=0;
    int n=num;
    int move=power(2,num)-1;
    printf("\ntotal number of moves:  %d\n",move);
    int flag;
	stack x;
    push(num,src,dest,spare,flag=1);
   
    abc:    if(num==1)
        {
            x=pop();
            printf("\nMove disk %d from %c to %c.",x.n,x.source,x.dest);
				i++;
            if(i==move)
				goto xyz;
            if(flag==1)
				goto pqr;
            if(flag==2)
				goto pqr;
        }
        num=num-1;
        char c=spare;
        spare=dest;
        dest=c;
        push(num,src,dest,spare,flag=1);
        goto abc;
    pqr:
        x=pop();
        printf("\nMove disk %d from %c to %c.",x.n,x.source,x.dest);i++;
        num=x.n-1;
        char c1=x.source;

        src=x.spare;
        spare=c1;
        dest=x.dest;
        push(num,src,x.dest,spare,flag=2);
   
        goto abc;
   xyz:
   	printf("");
}

int main(){
    int  n;
    printf("Insert number of disks :");
        scanf("%d", &n);
    nontoh(n, 'A', 'C','B');

}
