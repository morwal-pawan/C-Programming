#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp1,*fp2,*fp3;
	char vpname[10][10],vptype[10][10],vqname[10][10],vqtype[10][10],opr[10][10],c2,c,c1;
	int i,j,k=0,k1=0,k2=0,vpaddress[10],vqaddress[10],tp_origin,tq_origin,p_size,lp_origin,rf;
	int address[10],op[10];
	fp1=fopen("linker1.text","r");
	if(fp1==NULL)
	{
		printf("file1 error....\n");
		exit(0);
	}
	fscanf(fp1,"%d%d%d",&tp_origin,&p_size,&lp_origin);
	rf=lp_origin-tp_origin;
	while(c!=EOF)
	{
		fscanf(fp1,"%s%s%d",vpname[k],vptype[k],&vpaddress[k]);
		k++;
		c=fgetc(fp1);
		fseek(fp1,-1,SEEK_CUR);
	}
	fp2=fopen("linker2.text","r");
	if(fp2==NULL)
	{
		printf("file2 error....\n");
		exit(0);
	}
	fscanf(fp2,"%d",&tq_origin);
	while(c1!=EOF)
	{
			fscanf(fp2,"%s%s%d",vqname[k1],vqtype[k1],&vqaddress[k1]);
			k1++;
			c1=fgetc(fp2);
			fseek(fp2,-1,SEEK_CUR);
	}
	fp3=fopen("linker3.text","r");
	if(fp3==NULL)
	{
		printf("file3 error....\n");
		exit(0);
	}
	while(c2!=EOF)
	{
		fscanf(fp3,"%d%s%d",&address[k2],opr[k2],&op[k2]);
		k2++;
		c2=fgetc(fp3);
		fseek(fp3,-1,SEEK_CUR);
	}
	fclose(fp2);
	fclose(fp1);
	fclose(fp3);
	fp2=fopen("onepass.txt","w");
	fprintf(fp2,"\n one pass linker...\n");
	fprintf(fp2,"\n");
	fprintf(fp2,"tp_origin:%d\np_size:%d\nlp_origin:%d\nrf:%d",tp_origin,p_size,lp_origin,rf);
	fprintf(fp2,"\n");
	fprintf(fp2,"\n");
	for(i=0;i<k-1;i++)
		fprintf(fp2,"%s\t%s\t%d\n",vpname[i],vptype[i],vpaddress[i]);
	fprintf(fp2,"\n after reallocation....\n");
/*reallocation.....*/
	fprintf(fp2,"\n");
	for(i=0;i<k-1;i++)
	{
		if(strcmp(vptype[i],"EXT")==0)
		{
			fprintf(fp2,"%s\t%s\t%d\n",vpname[i],vptype[i],vpaddress[i]);
		}
		if(strcmp(vptype[i],"PD")==0)
		{
			fprintf(fp2,"%s\t%s\t%d\n",vpname[i],vptype[i],vpaddress[i]+rf);
		}
	}
	fprintf(fp2,"\n two pass linker...\n");
	fprintf(fp2,"\n");
	/*resolving external references...*/
	fprintf(fp2,"\n after linking....\n");
	fprintf(fp2,"\n");
	for(i=0;i<k-1;i++)
	{
		if(strcmp(vptype[i],"EXT")==0)
		{
			for(j=0;j<k1-1;j++)
			{
				if(strcmp(vpname[i],vqname[j])==0)
				{
				fprintf(fp2,"%s\t%s\t%d\n",vpname[i],vptype[i],(rf+tp_origin+p_size+vqaddress[j]-tq_origin));
				}
			}
		}
		if(strcmp(vptype[i],"PD")==0)
		{
			fprintf(fp2,"%s\t%s\t%d\n",vpname[i],vptype[i],vpaddress[i]+rf);
		}
	}
	fprintf(fp2,"\nreallocated  machine code...\n");
	fprintf(fp2,"\n");
	for(i=0;i<k2-1;i++)
	{
		fprintf(fp2,"%d\t%s\t0%d\n",(address[i])+rf,opr[i],op[i]);
	}
	fclose(fp2);
	return(0);
}
