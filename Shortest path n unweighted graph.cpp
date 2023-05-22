#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void Path(vector<int>adj[],int src,int v)
{
	bool visited[v]={false};
	int dist[v];
    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
    }
	visited[src]=true;
	queue<int>q;
	dist[src]=0;
	q.push(src);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
	   for(auto x: adj[temp])
	   {
		if(visited[x]==false)
		{
			dist[x]=dist[temp]+1;
			q.push(x);
			visited[x]=true;
		}
	  }
	}
	for(int i=0;i<v;i++)
	{
		cout<<dist[i]<<" ";
	}
}
int main()
{
	int v=4;
	vector<int>adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	addEdge(adj,1,3);
	cout<<"The adjacency list of matrix..\n";
	for(int i=0;i<v;i++)
	{
		cout<<i<<" | ";
		for(int v:adj[i])
		   cout<<v<<" ";
		cout<<endl;
	}
	int src=0; // source is given
	cout<<"\n\nThe Shortest path of given graph is ";
	Path(adj,src,v);
	return 0;
}
