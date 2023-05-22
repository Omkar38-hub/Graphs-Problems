// The DFS of graph can be done with the help of *STACK* data structure

#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void BFS(vector<int>adj[],int src,int v)
{
	bool visited[v]={false};
	stack<int>s;
	s.push(src);
	visited[src]=true;
	while(!s.empty())
	{
		int temp=s.top();
		cout<<temp<<" ";
		s.pop();
		for(auto x: adj[temp])
		{
			if(visited[x]==false)
			{
				s.push(x);
				visited[x]=true;
			}
		}
	}
}
int main()
{
	int v=6;
	vector<int>adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,0,5);
	addEdge(adj,1,3);
	addEdge(adj,3,5);
	addEdge(adj,2,4);
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
	BFS(adj,src,v);
	return 0;
}
