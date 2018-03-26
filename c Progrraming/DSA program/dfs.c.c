/*depth frist search technique */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 20
#define T 1
#define F 0
struct edge
{
	int terminal;
	struct edge *next;
};
struct vertex
{
	int visit;
	int vertex_no;
	char info;
	int path_length;
	struct edge *edge_ptr;
};
void input(int , int a[size][size]);
void output(int , int a[size][size]);
void dfs(int, int*dist ,struct vertex vert[size]);
struct edge *insert_vertex(int, struct edge *);
void table(int , int matrix[size][size],struct vertex vert[size]);
/*function main*/
void main()
{
	int i,n;
	int number , index , dist;
	int a[size][size];
	struct vertex vert[size];
	struct edge *list;
	printf("enter the number of vertex in the graph:");
	scanf("%d",&number);
	input(number, a);
	output(number, a);
	table(number,a,vert);
	printf("\n input the starting vertex 0-%d",number-1);
	scanf("%d",&index);
	dist = 0;
	dfs(index,&dist,vert);
	printf("\npath length of the vertex from %c", vert[index].info);
	printf("\n vertex length vertex connectivity \n");
	for(i=0;i<n;i++)
	{
		printf("\n%c%d",vert[i].info,vert[i].path_length);
		for(list=vert[i].edge_ptr;list;list=list->next)
			{
			printf("");
			putchar(list->terminal+'A');
			}
	}
}
/*input function to read adjency matrix*/
void input(int number,int a[size][size])
{
	int i,j;
	printf("\nenter the adjaceny matrix:\n");
	for(i=0;i<number;i++)
	{
		for(j=0;j<number;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
/*output  function*/
void output(int n , int a[size][size])
{
	int i,j;
	printf("\nädjcency matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
struct edge *insert_vertex(int vertex_no,struct edge *frist)
{
	struct edge *new1,*current;
	new1 = (struct edge*)malloc(sizeof(struct edge));
	new1->terminal = vertex_no;
	new1->next= NULL;
	if(!frist)
		return(new1);
	for(current=frist;current->next;current=current->next)
	{
		current->next=new1;
		return(frist);
	}
}
/*initilizing entries*/
void table(int vertex_no,int matrix[size][size],struct vertex vert[size])
{
	int i,j;
	for(i=0;i<vertex_no;i++)
	{
		vert[i].visit = F;
		vert[i].vertex_no = i+1;
		vert[i].info = 'A'+i;
		vert[i].path_length = 0;
		vert[i].edge_ptr = 0;
	}
	for(i=0;i<vertex_no;i++)
	{
		for(j=0;j<vertex_no;j++)
		{
			if(matrix[i][j]>0)
				vert[i].edge_ptr = insert_vertex(j, vert[i].edge_ptr);
		}
	}
}
/*computing path length*/
void dfs(int index,int *dist,struct vertex vert[size])
{
	struct edge *link;
	vert[index].visit=T;
	*dist+=1;
	for(link=vert[index].edge_ptr;link;link=link->next)
	{
		if(vert[link->terminal].visit==F)
			dfs(link->terminal,dist,vert);
	}
}
