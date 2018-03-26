#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp,*fp1,*fp2,*fp3,*fp4;
	int size[246],i,j,k=0,f=0,t1=0,t2=0,loc[10],mc=00;
	char symbol[246][5],reg[246][10],a[1000],ch3;
	char opcode[246][3],ch[10],ch1[10],z,*sym[10];
	fp=fopen("opcodes.txt","r");
	for(i=0;i<246;i++)
	{
		fscanf(fp,"%s",symbol[i]);
		fscanf(fp," %s",reg[i]);
		fscanf(fp," %s",opcode[i]);
		fscanf(fp,"%d",&size[i]);
	}
	fclose(fp);
	fp=fopen("program.txt","r");
	fp1=fopen("opcodetable.txt","w");
	fp2=fopen("symboltable.txt","w");
	fp3=fopen("opcodetable.txt","w");
	fp4=fopen("mctable.txt","w");
	while(1)
	{
		f=0;
		fscanf(fp," %s",ch);
		fscanf(fp," %s",ch1);
		for(i=0;i<246;i++)
		{
			if(strcmp(ch,symbol[i])==0 )
			{
				if(symbol[i]=="ADD")
					mc=01;
				if(symbol[i]=="SUB")
					mc=02;
				if(symbol[i]=="MULT")
					mc=03;
				if(symbol[i]=="MOV")
					mc=04;
				if(symbol[i]=="LOOP")
					mc=07;
				fprintf(fp4,"%s %d %s\n",symbol[i],1000+k,opcode[i]);
				fprintf(fp1,"%s %d\n",symbol[i],1000+k);
				k=k+size[i];
				break;	
			}
			/*	if(strcmp(ch,symbol[i]==0))
				{
					fprintf(fp1,"%s %d\n",symbol[i],1000+k);
					k=k+size[i];
					break;
				}*/			
		}
		if(i==246)
		{
		for(i=0;i<246;i++)
			{
			if(strcmp(ch,symbol[i])==0)
				{
					fprintf(fp1,"%s %s\n",symbol[i],opcode[i]);
					k=k+size[i];
					break;	
				}
		}
		}
		if(strcmp(reg[i],"x")==0)
		{
			fseek(fp,-(strlen(ch1)+1),SEEK_CUR);
		}
		if(i==246)
		{
		if(!isdigit(*ch))
		{
			for(i=0;i<=t1;i++)
			{
				if(sym[i]==ch)
					goto abc;	
			}
				sym[t1++]=ch;
				fprintf(fp2,"%s %d \n",ch,1000+k);
		}
	abc:		fseek(fp,-(strlen(ch1)+1),SEEK_CUR);
			continue;
		}
		if(strcmp(ch,"HLT")==0)
		{
			break;
		}
	}
	fclose(fp);
	fclose(fp1);   	
}
