#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main ()
{
	FILE *f1,*f2,*f3,*f4;
	char c2[10],name[10],name1[10],a[1000],a1[1000],c,ss[10],pntab[100],p[10],c1,*md[1000];
	int i,j,l,ch=0,k1=0,k=0,np=0,nk=0,t=0,t1=0,lt0=0,lt=0,lt1=0;
	char ap[10][10],fp[10][10],c3,c4;
	f1=fopen("macro.text","r");
	f3=fopen("onepass.text","w");
	f4=fopen("twopass.text","w");
	i=0;
	printf ("\n ASSEMBLY PROGRAM \n");
	printf("--------------------------------");
	fprintf(f3,"\n ...ONE PASS MACRO ...\n");
	fprintf(f3,"\n");
	while(c!=EOF)
	{
		c=fgetc(f1);
		a[i]=c;
		i++;
		k++;
	}
	k=k-1;
	while(ch<6)
	{
		printf("\n 1-macro name table:(NTAB): \n");
		printf("\n 2-perameter name table:(PNTAB):\n");
		printf("\n 3-sequence symbole:(SSNTAB):\n");
		printf("\n 4-macro defination:(MDT):\n");
		printf("\n 5-macro expanded code:\n");
		printf("\n 6-for exit\n");
		printf("\n enter ur choice\n");
		scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		rewind(f1);
		while(c1!=EOF)
		{
			scanf("%c",&c1);
			fscanf(f1,"%s",c2);
			if(strcmp(c2,"MACRO")==0)
			{
				fscanf(f1,"%s",name1);
				while(c4!='\n')
				{
					fscanf(f1,"%s",fp[lt0++]);
					c4=fgetc(f1);
					fseek(f1,-1,SEEK_CUR);
				}
				c3='\t';
				c4='\t';
				break;
			}
		}
		t=0;
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
										name[j]='\0';
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
				fprintf(f3,"\nmacro name table(NTAB):-: ");
				fprintf(f3,"\n");
				fprintf(f3,"%s",name);
				fprintf(f3,"\n");
			fprintf(f3,"------------------------------\n");
				break;
	case 2:
		fprintf(f3,"\n macro perameter(PNTAB):-\n");
		fprintf(f3,"\n");	
		l=l+1;
		while(a[l++]!='\t' && a[l--]!='\n')
		{
			while(a[l]!='\t')
			{
				pntab[k1++]=a[l++];
			}
			pntab[k1++]='\0';
			if(a[l++]=='\t')
				continue;
			else
				l--;
		}
			i=0;
			while(i<k1)
			{
				while(pntab[i]!='\0')
				{
					if(pntab[i]=='=')
					{
						nk++;
					}
					fprintf(f3,"%c",pntab[i++]);
				}
				fprintf(f3,"\n");
				np++;
				i++;
				fprintf(f4,"\n");
			}
			fprintf(f3,"\n");
			fprintf(f3,"\n no. of positional perameter:(pp):%d\n",np-nk);
			fprintf(f3,"\n no. of keyword perameter:(kp):%d\n",nk);
		fprintf(f3,"----------------------------------\n");
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
				ss[j++]='\0';
			}
		}
		fprintf(f3,"\n");
		fprintf(f3,"sequential symbols(SSTAB):-\t%s\n",ss);
		fprintf(f3,"\n-----------------------------------\n");
		break;
	case 4:
		fprintf(f4,"TWO PASS MACRO \n");
		fprintf(f4,"macro defination:\n");
		fprintf(f4,"\n");
		for(i=0;i<k;i++)
			fprintf(f4,"%c",a[i]);
		fprintf(f4,"\n");
		fprintf(f4,"\n-------------------------------------\n");
		break;
	case 5:
		fprintf(f4,"\n expanded code....\n");
		fprintf(f4,"\n");
		f2=fopen("program.text","r");
		if(f2==NULL)
		{
			printf("file opening error...\n");
			exit(1);
		}
		c4='\t';
		i=0,j=0,t=0,lt1=0;
		while(c1!=EOF)
		{
			fscanf(f2,"%s",c2);
			if(strcmp(c2,name1)==0)
			{
				lt=0;
				lt1=0;
				fprintf(f4,"macro calling...\n");
				while( c4!='\n')
				{
					fscanf(f2,"%s",ap[lt++]);
					c3=fgetc(f2);
					c4=fgetc(f2);
					fseek(f2,-1,SEEK_CUR);
				}
				c3='\n';
				c4='\t';
				i=0;
				rewind(f1);
				while(c1!=EOF)
				{
					fscanf(f1,"%s",c2);
					if(strcmp(c2,name1)==0)
					{
						c1=1;
						while(c1!='\n')
						{
							fscanf(f1,"%c",&c1);
						}
						fprintf(f4,"\n starting of macro expansion...\n ");
						printf("\n");
						while(c1!=EOF)
						{
						fscanf(f1,"%s",c2);
						if(strcmp(c2,"&REG")==0)
							{
								fprintf(f4,"AREG");
								goto pkm;
							}
						if(strcmp(c2,fp[i])==0)
						{
							i++;
							fprintf(f4,"%s",ap[lt1]);
							lt1++;
					pkm:	goto hkm;
						}
							fprintf(f4,"%s",c2);
					hkm:	c1=fgetc(f1);
							fseek(f1,-1,SEEK_CUR);
							if(c1=='\t')
								fprintf(f4," ");
							if(c1=='\n')
								fprintf(f4,"\n");
						}
						fprintf(f4,"\n");
					}
				}
				
			}
			fprintf(f4,"%s",c2);
			c1=fgetc(f2);
			fseek(f2,-1,SEEK_CUR);
			if(c1=='\t')
				fprintf(f4," ");
			if(c1=='\n')
				fprintf(f4,"\n");
		}
		fprintf(f4,"\n");		
		break;	
	case 6:	
			exit(0);
			printf("--------------------------------\n");
				break;
	default: 
		printf("\nWRONG OPTION:PROGRAM TERMINATED\n");
		exit(0);
		break;
		}
	}
	fclose(f1);
	fclose(f2);
}
