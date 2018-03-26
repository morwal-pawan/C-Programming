/* SHORTEST PATH*/
#include<stdio.h>
#include<conio.h>
#define size 10
int a[size][size];
int p[size][size];
int m[size][size];
int i,j,k,n;
void input();
void warshall();
void modified_warshall();
void output();
int main()
{
	input();
	warshall();
	output();
	printf("shortest path matrix from modified warshall:\n");
	modified_warshall();
	return 0;
}
/*input function*/
void input()
{
	printf("enter the number of vertices:");
	scanf("%d",&n);
	printf("enter the adjcency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}	
}
/*output function*/
void output()
{
	printf("shortest path matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}	
}
/*shortest path function*/
void warshall()
{
	/*initilization of the matrix*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
				p[i][j] =0;
			else
				p[i][j]=1;
		}
	}
/*shortest path evilution starts from here*/
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		for(k=0;k<n;k++)
		{
			p[i][j] = p[i][j] | p[i][k] & p[k][j];
		}
	}
}
}
void modified_warshall()
{
	/*initiliation of matrix*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
				m[i][j]=999;
			else
				m[i][j]=a[i][j];		
		}
	}
	/*shortest path function*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
			if(a[i][j]<= m[i][k] + m[k][j])
				m[i][j] = m[i][j];
			else
				m[i][j] = m[i][k] + m[k][j];
		   }
		}
	}
for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
}

