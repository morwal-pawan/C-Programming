#include<stdio.h>
#include<sys/time.h>
#define white 0
#define gray 1
#define black 2
#define max_node 1000
#define max 100000
int n,e,capacity[max_node][max_node],flow[max_node][max_node],colour[max_node];
int pred[max_node],capacity1[max_node][max_node];
int q[max_node+2],head=0,tail=0,total_flow=0;
int minimum(int x,int y)
{
	return(x<y?x:y);
}
int enqueue(int x)
{
	q[tail++]=x;
	colour[x]=gray;
}
int dequeue()
{
	int x;
	x=q[head];
	head++;
	colour[x]=black;
	return(x);
}
int bfs(int s,int t)
{
	int v,u,i;
	head=tail=0;
	enqueue(s);
	pred[s]=-1;
	while(head!=tail)
	{
		u=dequeue();
		for(v=0;v<=n-1;v++)
		{
				if(colour[v]==white && capacity[u][v]>0)
				{
					enqueue(v);
					pred[v]=u;
				}
		}
	}
	return(colour[t]==black);
}
int max_flow(int source,int sink)
{
	int i,j,u,inr;
	inr=max;
	for(u=n-1;pred[u]>=0;u=pred[u])
	{
			inr=minimum(inr,(capacity[pred[u]][u]-flow[pred[u]][u]));
	}
	for(u=n-1;u>0;u=pred[u])
	{
		capacity[pred[u]][u]=capacity[pred[u]][u]-inr;
	}
		total_flow=total_flow+inr;
}

int main()
{
	int a,b,c,i,j,ch;
	FILE *fp;
	printf("\n FORD FULKERSION MAX FLOW PROBLEM \n");
	fp=fopen("input.text","r");
	if(fp==NULL)
		{
			printf("file error....\n");
			return;
		}
	fscanf(fp,"%d%d",&n,&e);
	ch=n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			flow[i][j]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			capacity[i][j]=0;
	printf("Given capacity:\n");
	for(i=0;i<e;i++)
	{
		fscanf(fp,"%d%d%d",&a,&b,&c);
		printf("edge: %d\t to edge: %d is: %d \n",a,b,c);
		capacity[a][b]=c;
		capacity1[a][b]=c;
	}
	struct timeval tim;
    double timestart,timeend,executiontime;
 	gettimeofday(&tim,NULL);
 	timestart=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
	while(ch>0)
 	{
 		for(i=0;i<n+n;i++)
 		{
 			pred[i]=0;
 			q[i]=0;
 			colour[i]=0;
 		}
		bfs(0,n-1);
		max_flow(0,n-1);
		ch--;
  	}
   gettimeofday(&tim,NULL);
   timeend=(double)tim.tv_sec+(double)(tim.tv_usec/1000000.0);
   executiontime=timeend-timestart;
   printf("\ntime taken in max flow problem:%f\n",executiontime);
 	printf("\nmax flow possible is :%d\n",total_flow);
	printf("\n MIN CUT PROBLEM \n");
  printf("for minimum cut edge should be cut...\n");
  for(i=0;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{
  		if((colour[i]==1 || colour[i]==2) && colour[j]==0)
  		{
  			if(capacity1[i][j] || capacity[j][i]>0)
  				printf("edge: %d - %d\n",i,j);
  		}
  	}
  }
	fclose(fp);
	return 0;
}
