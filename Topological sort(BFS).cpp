#include<bits/stdc++.h> 
using namespace std; 

vector<int> BFS(vector<int> adj[],int V,int inDegree[])
{
	vector<int>v;
	queue<int>q;
	for(int i=0;i<V;i++)
	{
		if(inDegree[i]==0)
		   q.push(i);
	}
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		v.push_back(temp);
		for(int x: adj[temp])
		{
			inDegree[x]--;
			if(inDegree[x]==0)
			   q.push(x);
		}
	}
	return v;
}

void addEdge(vector<int> adj[], int u, int v,int inDegree[]){
    adj[u].push_back(v);
    inDegree[v]++;
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	int inDegree[V]={0};
	addEdge(adj,0,2,inDegree);
	addEdge(adj,0,3,inDegree);
	addEdge(adj,1,4,inDegree);
	addEdge(adj,2,3,inDegree);
	addEdge(adj,1,3,inDegree);
    cout<<"The adjacency list of matrix..\n";
	for(int i=0;i<V;i++)
	{
		cout<<i<<" | ";
		for(int v:adj[i])
		   cout<<v<<" ";
		cout<<endl;
	}
	cout<<"\nThe toplogical sort of given graph is ";
	vector<int>v=BFS(adj,V,inDegree);
	for(auto x: v)
	   cout<<x<<" ";
	return 0; 
} 

