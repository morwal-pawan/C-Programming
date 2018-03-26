#include<stdio.h>
int p,q,t=1,k;
int power(int p,int q)
{
	if(q==0)
		return(1);
	for(k=1;k<=q;k++)
	{
		t=t*p;
	}
	return(t);
}
int hextodec(char s[])
{
	char a,b,c,d,e,f,A,B,C,D,E,F;
	long int h=0;
	int i,j,m=0;
	for(i=0;s[i]!='\0';i++);
	for(j=i-1;j>=0;j--)
	{
		if(s[j]=='a'||s[j]==A)
			h=h+10*power(16,m++);
		else if(s[j]=='b'||s[j]==B)
			h=h+11*power(16,m++);
		else if(s[j]=='c'||s[j]==C)
			h=h+12*power(16,m++);
		else if(s[j]=='d'||s[j]==D)
			h=h+13*power(16,m++);
		else if(s[j]=='e'||s[j]==E)
			h=h+14*power(16,m++);
		else if(s[j]=='f'||s[j]==F)
		{
			h=h+15*power(16,m++);
	    }
			else
			{
				h=h+9*(power(16,m++));
				
			}
	}
	
	return(h);
}
int dectohex(long int n)
{
	int p,i,k=0;
	char h[32],a,b,c,d,e,f,A,B,C,D,E,F;
	while(n>9)
	{
		p=n%16;
		if(p==10)
			h[k++]='A';
		else if(p==11)
			h[k++]='B';
		else if(p==12)
			h[k++]='C';
		else if(p==13)
			h[k++]='D';
		else if(p==14)
			h[k++]='E';
			else
				h[k++]='F';
		n=n/16;
	}
		printf("%d",n);
	for(i=k-1;i>=0;i--)
		printf("%c",h[i]);
}
int main()
{
	int d;
	long int q;
	char s[32];
	printf("enter hexadecimal string:");
	scanf("%s",s);
	d=hextodec(s);
 	printf("decimal number of %s is: %d ",s,d);
 	printf("\nenter integer number:");
 	scanf("%ld",&q);
 	dectohex(q);
	return 0;
}
