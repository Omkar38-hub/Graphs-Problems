#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
bool BFSRec(vector<int>adj[],int src,bool visited[],int parent)
{
	stack<pair<int,int>>s;
	visited[src]=true;
	s.push({src,parent});
	while(!s.empty())
	{
		int temp=s.top().first;
		int p=s.top().second;
		s.pop();
	  for(auto x: adj[temp])
	  {
		if(visited[x]==false)
		{
			//cout<<temp<<" "<<x<<endl;
			s.push({x,temp});
			visited[x]=true;
		}
		else if(x!=p)
		{
			cout<<x<<" ";
			return true;
		}
		
	  }
	}
	return false;
}

bool BFS(vector<int>adj[],int V)
{
	bool visited[V]={false}; 
	for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(BFSRec(adj,i,visited,-1)==true)
                return true;
            }
    }
	return false;
}
int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,1,2);
	addEdge(adj,1,4);
	addEdge(adj,2,3);
    cout<<"The adjacency list of matrix..\n";
	for(int i=0;i<V;i++)
	{
		cout<<i<<" | ";
		for(int v:adj[i])
		   cout<<v<<" ";
		cout<<endl;
	}
	cout<<"\n\nIs the cycle is present in given graph  \n";
	if(BFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0; 
} 

