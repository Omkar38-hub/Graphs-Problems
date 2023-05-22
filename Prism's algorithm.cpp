#include<bits/stdc++.h>
using namespace std;
# define V 4

void printMST(int parent[],int graph[V][V])
{
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<" - "<<i<<" = "<<graph[i][parent[i]]<<endl;
	}
}
int primMST(int graph[V][V])
{ 
  int key[V];
  bool inMST[V];
  int parent[V]; 
  parent[0]=-1;
  for(int i=0;i<V;i++)
  {
  	key[i]=INT_MAX;
  	inMST[i]=false;
  }
  key[0]=0;
  int result=0;
  for(int i=0;i<V;i++)
  {
  	int u;
  	int mn=INT_MAX;
  	for(int j=0;j<V;j++)
  	{
  		if(!inMST[j] && (key[j]<mn))
  		{
  			mn=key[j];
  			u=j;
     	}
	}
	inMST[u]=true;
	result+=key[u];
	for(int j=0;j<V;j++)
	{
		if(!inMST[j]&& graph[u][j]!=0 && key[j]>graph[u][j])
		{
			//cout<<j<<endl;
			parent[j]=u; 
			key[j]=graph[u][j];
			
		}  
	}
  }
  printMST(parent,graph);
  return result;
}
int main()
{
	int graph[V][V] = { { 0, 5, 8, 0}, 
						{ 5, 0, 10, 15 }, 
						{ 8, 10, 0, 20 }, 
						{ 0, 15, 20, 0 },}; 
	cout<<"\nThe minimum cost Spanning tree by Prism's is \n";
	cout<<primMST(graph); 
	return 0;
}

