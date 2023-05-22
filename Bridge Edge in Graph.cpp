#include<bits/stdc++.h>
using namespace std;
void DFS(vector<pair<int,int>>&vp,int u,vector<int> adj[],int parent[],int disc[],int low[],bool visited[])
    {
        static int time1=0;
        disc[u]=low[u]=++time1;
        visited[u]=true;
        for(int v: adj[u])
        {
            if(!visited[v])
            {
                parent[v]=u;
                DFS(vp,v,adj,parent,disc,low,visited);
                low[u]=min(low[u],low[v]);
                if (low[v] > disc[u]) 
			    {
			       vp.push_back({u,v});
			    }
            }
            else if(v!=parent[u])
               low[u]=min(low[u],disc[v]);
        }
    }
void isBridge(int V, vector<int> adj[]) 
    {
        int parent[V];
        int disc[V];
        int low[V];
        bool visited[V];
        for (int i = 0; i < V; i++) 
	    { 
		parent[i] = -1; 
		visited[i] = false; 
	    } 
        vector<pair<int,int>>vp;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS(vp,i,adj,parent,disc,low,visited);
            }
        }
        cout<<"The bridge Edges of graph is\n";
        for(auto x: vp)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    
void addEdge(vector<int>adj[],int u,int v)  
{
	adj[u].push_back(v);
	adj[v].push_back(u);
 } 
int main()
{
	int V=4;
	vector<int>adj[V];
	addEdge(adj,0,1);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	isBridge(V ,adj);
	return 0;
}
