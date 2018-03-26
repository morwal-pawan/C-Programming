#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int power_of(int,int);
struct poly
{	int cof;
	int exp;
}*a,*b,*c;
main()
{
  int i,j,n,x,z,m,p,c1=0,t;
  char q;
  FILE *fp;
  fp=fopen("source.txt","r");
  fscanf(fp,"%d",&n);
  fscanf(fp,"%d",&m);
if(fp==NULL)
	printf("FILE DOES NOT EXIST...\n");
a=(struct poly*)malloc(n*sizeof(struct poly));
	for(i=0;i<n;i++)
	{	fscanf(fp,"%d",&a[i].cof);
		fscanf(fp,"%d",&a[i].exp);
	}
c=(struct poly*)malloc((m*n)*sizeof(struct poly));
b=(struct poly*)malloc(m*sizeof(struct poly));
	for(i=0;i<m;i++)
	{	fscanf(fp,"%d",&b[i].cof);
		fscanf(fp,"%d",&b[i].exp);
	}
  printf("enter your choice...\n");
  printf("addition       1...\n");
  printf("multiplication 2...\n");
  printf("evalution     3...\n");
  printf("exit           4...\n");
   scanf("%d",&z);
	switch(z)
	{	case 1:
			printf("  addition  ...\n");
			int i,j,k;
			i = j = k = 0;
			while ( i <n && j <m)
			{
				if( a[i].exp > b[j].exp)
				{
					c[k] = a[i];
					k++;
					i++;
				}
				else
				{
					if( a[i].exp < b[j].exp)
					{
						c[k] = b[j];
						k++;
						j++;
					}
					else
					{
						c[k].exp = a[i].exp;
						c[k].cof = a[i].cof + b[j].cof;
						i++;
						j++;
						k++;
					}
				}
            }
			while( i <n )
			   {
			     c[k] = a[i];
			     k++;
			     i++;
		       }
			while( j <m )
			    {
			      c[k] = b[j];
			      k++;
		          j++;
		        }
	        printf("i st poly is=");
        for(i=0;i<n;i++)
        {
        printf("%d\t%d\n",a[i].cof,a[i].exp);
        }
        printf("2 nd poly is");
         for(i=0;i<m;i++)
         {
        printf("%d\t%d\n",b[i].cof,b[i].exp);
        }
	        printf("YOUR RESULTANT POLYNOMIAL IS ...\n");
			for(i=0;i<k;i++)
			{
				printf(" %d  %d\n",c[i].cof,c[i].exp);
            }
				break;
		case 2:
             k=0;
			for(i=0;i<n;i++)
			 {
              for(j=0;j<m;j++)
               {
               if(a[i].cof==b[j].cof)
               {
                c[k].cof=a[i].cof*b[j].cof;
                c[k].exp=a[i].exp+b[j].exp;
                k++;
               }
               else
               {
               c[k].cof=a[i].cof*b[j].cof;
               c[k].exp=a[i].exp+b[j].exp;
               k++;}
               }
             }
			printf("RESULTANT IS=");
		for(i=0;i<k;i++)
		  printf("%dx^%d+",c[i].cof,c[i].exp);
             break;
		case 3:
			printf("ENTER VALUE OF 'x' ...\n");
			scanf("%d",&x);
			i=0;
			while(i<n)
			{	t=power_of(x,a[i].exp);
			 printf("%d",t);
			   c1=c1+t*a[i].cof;
				i++;
			}
			printf("EVALUTED VALUE OF YOUR POLYNOMIAL 1 IS... %d \n",c1);
			break;
		case 4:
			printf(" YOUR PROGRAM IS EXITING...\n ARE YOU SURE YOU WANT YOU EXIT...\n 'PRESS E' \n");
			scanf("%c",&q);
			if(q=='E'||q=='e')
			                  exit(1);
   }
	getch();}
int power_of(int x,int y)
{
 int i,p=1;
 for(i=0;i<y;i++)
    p=p*x;
 return(p);
}
