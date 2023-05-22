#include<bits/stdc++.h>
using namespace std;

void DFS(int s,bool visited[],vector<int>adj[])
{
	visited[s]=true;
	for(int x: adj[s])
	{
		if(!visited[x])
		   DFS(x,visited,adj);
	}
}
bool isConnected(int V,vector<int>adj[])
{
	bool visited[V]={false};
	
	// find a vertex with non-zero degree
	int i;
	for(i=0;i<V;i++)
	{
		if(adj[i].size()!=0)
		  break;
	}
	if(i==V)
	  return true;
	DFS(i,visited,adj);
	// check if all non-zero degree are visited
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false && adj[i].size()>0)
		   return false;
	}
	return true;
}

void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	int V=5;
	vector<int>adj[V];
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,2,4);
	addEdge(adj,4,0);
	cout<<"The adjacency list representation of graph is \n";
	for(int i=0;i<V;i++)
	{
		cout<<i<<" | ";
		for(int x: adj[i])
		   cout<<x<<" ";
		cout<<endl;
	}
	cout<<"Is graph connected or not ?\n";
	if(isConnected(V,adj))
	   cout<<"YES\n";
	else
	   cout<<"NO\n";
	return 0;
}
