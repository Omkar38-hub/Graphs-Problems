#include<bits/stdc++.h>
using namespace std;
stack<int>st;
void DFS(int u,vector<int> adj[],bool recst[],int disc[],int low[],bool visited[])
    {
        static int time1=0;
        st.push(u);
        disc[u]=++time1;
        low[u]=time1;
        visited[u]=true;
        recst[u]=true;
        for(int v: adj[u])
        {
            if(!visited[v])
            {
                //parent[v]=u;
                DFS(v,adj,recst,disc,low,visited);
                low[u]=min(low[u],low[v]);
            }
            else if(recst[v])
               low[u]=min(low[u],disc[v]);
        }
	   if (low[u] == disc[u]) 
	   { 
	   vector<int>p;
		while (st.top() != u) 
		{ 
			p.push_back(st.top());
			recst[st.top()] = false; 
			st.pop(); 
		} 
		p.push_back(st.top());
		recst[st.top()] = false; 
		st.pop(); 
		for(auto k: p)
		  cout<<k<<" ";
		cout<<endl;
	  }
}
    void tarjans(int V, vector<int> adj[])
    {
        int disc[V];
        int low[V];
        bool visited[V];
        bool recst[V];
        for (int i = 0; i < V; i++) 
	    { 
		visited[i] = false; 
		recst[i]=false;
	    } 
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS(i,adj,recst,disc,low,visited);
            }
        }
    }
    
void addEdge(vector<int>adj[],int u,int v)  
{
	adj[u].push_back(v);
 } 
int main()
{
	int V=5;
	vector<int>adj[V];
	addEdge(adj,1,0);
	addEdge(adj,0,2);
	addEdge(adj,2,1);
	addEdge(adj,0,3);
	addEdge(adj,3,4);
	cout<<"The strongly connected components of graph are\n";
	tarjans(V ,adj);
	return 0;
}
