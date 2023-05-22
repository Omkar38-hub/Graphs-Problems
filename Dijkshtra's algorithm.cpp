#include<bits/stdc++.h>
using namespace std;
# define V 4

void printPath(int parent[], int j)
{
      
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
  
    printPath(parent, parent[j]);
  
    printf("-> %d ", j);
}
void printMST(int src,int distance[V],int parent[V])
{
	for(int i=0;i<V;i++)
	{
		cout<<"\n"<<src<<" - "<<i<<" = "<< distance[i]<<endl<<"Path: "<<src;
		printPath(parent,i);
	}
}
void Dijshtra(int graph[V][V],int src)
{ 
  int distance[V];
  bool inMST[V];
  int parent[V]; 
  parent[src]=-1;
  for(int i=0;i<V;i++)
  {
  	distance[i]=INT_MAX;
  	inMST[i]=false;
  }
  distance[src]=0;
  for(int i=0;i<V-1;i++)
  {
  	int u;
  	int mn=INT_MAX;
  	for(int j=0;j<V;j++)
  	{
  		if(!inMST[j] && (distance[j]<mn))
  		{
  			mn=distance[j];
  			u=j;
     	}
	}
	inMST[u]=true;
	for(int j=0;j<V;j++)
	{
		if(!inMST[j]&& graph[u][j]!=0 && distance[j]>distance[u]+graph[u][j])
		{
			parent[j]=u; 
			distance[j]=distance[u]+graph[u][j];
			
		}  
	}
  }
  printMST(src,distance,parent);
}
int main()
{
	int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 
	cout<<"\nThe Dijkshtra's shortest Path' is \n";
	Dijshtra(graph,0); 
	return 0;
}

