#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void disple();
int main()
{
 FILE *fp,*fp1;
 char ch;
 int *a,i,j,i1,s,b,c,min,pos,temp,n;
 fp=fopen("input.txt","r+");
 fp1=fopen("output.txt","w+");
 fscanf(fp,"%d",&n);
 a=(int*)calloc(n,sizeof(int));
  for(i=0;i<n;i++)
   {
    fscanf(fp,"%d",&a[i]);
   }
  for(i=0;i<n;i++)
   {
    printf("CURRENT ARRAY IS=%d\n",a[i]);
   }
   do
{
  disple();
  printf("enter the option=");
  scanf("%c",&ch);
  fp1=fopen("output.txt","w+");
  if(ch=='s')
   {
    for(i=0;i<n;i++)
       {
       min=a[i];
       pos=i;
        for(j=i+1;j<n;j++)
          {
            if(a[j]<min)
              {
                min=a[j];
                pos=j;
               }
           }
          temp=a[i];
          a[i]=a[pos];
          a[pos]=temp;
       }
       fprintf(fp1,"RESULT AFTER SELECTION SORT=");
       for(i=0;i<n;i++)
       {
         fprintf(fp1,"%d\n",a[i]);
       }
    }
   else if(ch=='b')
    {
      for(i1=1;i1<n;i1++)
      {
       for(j=i1-1;j>=0;j--)
        {
         if(a[j+1]<a[j])
          {
            c=a[j+1];
            a[j+1]=a[j];
            a[j]=c;
           }
         }
      }
      fprintf(fp1,"RESULT AFTER BUBBLE SORT=");
      for(i1=0;i1<n;i1++)
       {
        fprintf(fp1,"%d\n",a[i1]);
       }
       }
      else if(ch=='r')
       {
       i=1;
       a[i-1]=a[i+1];
       a[i+2]=a[i];
       a[i+3]=a[i+7];
       a[i+5]=a[i];
       fprintf(fp1,"RESULT AFTER RANDOMISE=");
       fp1=fopen("output.txt","w+");
       for(i=0;i<n;i++)
        {
         fprintf(fp1,"%d\n",a[i]);
        }
       }
       else if(ch=='i')
       {
        for(i=1;i<n;i++)
        {
          temp=a[i];
          j=i-1;
          while(j>=0&&temp<a[j])
          {
           a[j+1]=a[j];
           j--;
          }
          a[j+1]=temp;
        }
        fprintf(fp1,"RESULT AFTER INSERTION SORT=");
        fp1=fopen("output.txt","w+");
         for(i=0;i<n;i++)
          {
           fprintf(fp1,"%d\n",a[i]);
          }
       }
      else if(ch=='e')
      {
      exit(1);
      }
  }while(1);
      fclose(fp);
      fclose(fp1);
      getch();
 }
void disple()
{
  printf("PRESS 'b' for bubble sort.....\n");
  printf("PRESS 's' for selection sort.....\n");
  printf("PRESS 'r' for random.....\n");
  printf("PRESS 'd' for disple.....\n");
  printf("PRESS 'e' for exit.....  \n");
}
