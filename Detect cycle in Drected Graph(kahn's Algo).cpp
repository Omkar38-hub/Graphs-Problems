#include<bits/stdc++.h> 
using namespace std; 

bool BFS(vector<int> adj[],int V,int inDegree[])
{
	vector<int>v;
	queue<int>q;
	for(int i=0;i<V;i++)
	{
		if(inDegree[i]==0)
		   q.push(i);
	}
	int count=0;
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
		count++;
	}
	if(count==V)
	  return false;
	else
	  return true;
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
	addEdge(adj,0,1,inDegree);
	addEdge(adj,1,2,inDegree);
	addEdge(adj,2,3,inDegree);
	addEdge(adj,3,1,inDegree);
	addEdge(adj,4,1,inDegree);
    cout<<"The adjacency list of matrix..\n";
	for(int i=0;i<V;i++)
	{
		cout<<i<<" | ";
		for(int v:adj[i])
		   cout<<v<<" ";
		cout<<endl;
	}
	cout<<"\n\nIs the cycle is present in given graph  \n";
	if(BFS(adj,V,inDegree))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";
	return 0; 
} 

