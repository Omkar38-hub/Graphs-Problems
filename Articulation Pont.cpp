#include<bits/stdc++.h>
using namespace std;
void APUtil(int u,vector<int>adj[],bool visited[],int disc[],int low[],int parent[],bool ap[])
{
	static int time = 0; 
	int children = 0; 
	visited[u] = true; 
	disc[u] = low[u] = ++time; 
	for (int v: adj[u]) 
	{ 
		if (!visited[v]) 
		{ 
			children++; 
			parent[v] = u; 
			APUtil(v,adj, visited, disc, low, parent, ap); 
			low[u] = min(low[u], low[v]); 
			if (parent[u] == -1 && children > 1) 
				ap[u] = true; 
			if (parent[u] != -1 && low[v] >= disc[u]) 
				ap[u] = true; 
		} 

		else if (v != parent[u]) 
			low[u] = min(low[u], disc[v]); 
	} 
}
void ApPoint(int V,vector<int>adj[])
{
	bool visited[V] = {false}; 
	int disc[V]; 
	int low[V]; 
	int parent[V] = {-1}; 
	bool ap[V] = {false}; 
	for (int i = 0; i < V; i++) 
	{
		if (visited[i] == false) 
			APUtil(i,adj, visited, disc, low, parent, ap);
	} 
	for (int i = 0; i < V; i++) 
	{
		if (ap[i] == true) 
			cout << i << " "; 
	}	
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
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);
	cout<<"The artculation points of given graph are \n";
	ApPoint(V,adj);
	return 0;
}
