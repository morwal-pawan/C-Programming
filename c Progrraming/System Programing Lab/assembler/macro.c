#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct sym
{

	char lab[10];
	int val;
};
void main ()
{
	FILE *f1;
	char name[10],a[1000],c,ss[10];
	int i,j,l,ch=0,k=0;
	struct sym s[10];
	f1=fopen("macro.text","r");
	i=0;
	printf ("\n ASSEMBLY PROGRAM \n");
	printf("--------------------------------");
	printf("\n");
	while(c!=EOF)
	{
		c=fgetc(f1);
		a[i]=c;
		printf("%c",c);
		i++;
		k++;
	}
	k=k-1;
	while(ch<4)
	{
		printf("1-macro name table:(NTAB): \n");
		printf("2-perameter name table:(PNTAB):\n");
		printf("3-sequence symbole:(SSNTAB):\n");
		printf("4-for exit\n");
		printf("enter ur choice\n");
		scanf("%d",&ch);
	switch(ch)
	{
	case 1:
			for(i=0;i<10;i++)
			{
				if(a[i]=='M')
				{
					if(a[++i]=='A')
					{
						if(a[++i]=='C')
						{
							if(a[++i]=='R')
							{
								if(a[++i]=='O')
								{
									{
										j=0;
										i++;
										while(a[i]!='\t')
										{
											name[j++]=a[i];
											i=i+1;
										}
										if(a[i]=='\t')
											goto abc;;
									}
								}
							}
						}
					}
				}
			}
	abc: 	l=i;
				printf("\nmacro name table(NTAB):-: ");
				for(i=0;i<j;i++)
					printf("%c",name[i]);
				printf("\n");
			printf("------------------------------\n");
				break;
	case 2:
		printf("macro perameter(PNTAB):-\n");
		l=l+1;
		while(a[l]!='\n')
		{
			while(a[l]!='\t')
			{
				printf("%c",a[l++]);
			}
			
			l++;
			printf("\n");
		}
		printf("----------------------------------\n");
		break;
	case 3:
		j=0;
		for(i=0;i<k;i++)
		{
			if(a[i]=='.'&&a[i-1]!='\n')
			{
			
				if(a[++i]=='\t')
					continue;
				else
					i--;
				while(a[++i]!='\n')
				{
					
					ss[j++]=a[i];
				}
				ss[j++]=',';
			}
		}
		printf("sequential symbols(SSTAB):-\t%s\n",ss);
		printf("-----------------------------------\n");
		break;
	case 4:	
			exit(0);
			printf("--------------------------------\n");
					break;
				default: printf("\nWRONG OPTION:PROGRAM TERMINATED\n");
					break;
				}
		}
		fclose(f1);
	}
