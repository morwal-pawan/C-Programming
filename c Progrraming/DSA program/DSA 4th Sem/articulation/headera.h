#define max_node 1000
int articulation(int n,int e,int adj[][max_node]);
int bfs(int s,int t,int adj[][max_node],int adj2[][max_node],int ch);
int enqueue(int x);
int dequeue();
