#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	fp=fopen("string.cpp","r");
	if(fp==NULL)
	{
		printf("file does not exist...");
		exit(0);
	}
	while(1)
	{
		ch=fgetc(fp);
		if(ch==EOF)
			break;
		printf("%c",ch);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
