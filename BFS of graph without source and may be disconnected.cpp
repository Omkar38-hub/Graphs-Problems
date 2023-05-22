// The BFS of graph can be done with the help of *QUEUE* data structure

#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void BFS(vector<int>adj[],int src,bool visited[])
{
	queue<int>q;
	q.push(src);
	visited[src]=true;
	while(!q.empty())
	{
		int temp=q.front();
		cout<<temp<<" ";
		q.pop();
		for(auto x: adj[temp])
		{
			if(visited[x]==false)
			{
				q.push(x);
				visited[x]=true;
			}
		}
	}
}
int main()
{
	int v=7;
	vector<int>adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,3);
	addEdge(adj,2,3);
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);
	cout<<"The adjacency list of matrix..\n";
	for(int i=0;i<v;i++)
	{
		cout<<i<<" | ";
		for(int v:adj[i])
		   cout<<v<<" ";
		cout<<endl;
	}
	cout<<"\n\nThe BFS traversal of given graph is ";
	bool visited[v]={false};
	int count=0;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			BFS(adj,i,visited);
			count++;
		}   
		   
	}
	cout<<"\n\nNumber of disconnected components or number of islands is "<<count;
	
	return 0;
}
