// The DFS of graph can be done with the help of *STACK* data structure

#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void DFS(vector<int>adj[],int src,bool visited[])
{
	visited[src]=true;
	cout<<src<<" ";
	for(auto x: adj[src])
	{
		if(visited[x]==false)
		{
			DFS(adj,x,visited);
		}
	}
}
int main()
{
	int v=6;
	vector<int>adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,2,3);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,4,5);
	cout<<"The adjacency list of matrix..\n";
	for(int i=0;i<v;i++)
	{
		cout<<i<<" | ";
		for(int v:adj[i])
		   cout<<v<<" ";
		cout<<endl;
	}
	int src=0; // source is given
	cout<<"\n\nThe DFS traversal of given graph is ";
	bool visited[v]={false};
	DFS(adj,src,visited);
	return 0;
}
