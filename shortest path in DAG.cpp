#include<bits/stdc++.h> 
using namespace std; 

int weight[1001][1001];
void DFS(vector<int> adj[], int u,stack<int> &st, bool visited[]) 
{ 	
    visited[u]=true;
    
    for(int v:adj[u]){
        if(visited[v]==false)
            DFS(adj,v,st,visited);
    }
    st.push(u);
}


void topologicalSort(vector<int> adj[], int V,vector<int>&vec) 
{ 
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
	stack<int> st;
    
    for(int u=0;u<V;u++){
        if(visited[u]==false){
            DFS(adj,u,st,visited);
        }
    }
    
    while(st.empty()==false){
        int u=st.top();
        st.pop();
        vec.push_back(u);
    }
   
}
void shortestPath(vector<int> adj[], int V)
{
	vector<int>vec;
	topologicalSort(adj,V,vec);
	int distance[V];
	for(int i=0;i<V;i++)
	   distance[i]=INT_MAX;
	distance[vec[0]]=0;
	for(int i=0;i<vec.size();i++)
	{
		for(int x: adj[vec[i]])
		{
			if(distance[x]>distance[vec[i]]+weight[vec[i]][x])
			   distance[x]=distance[vec[i]]+weight[vec[i]][x];
		}
	}
	for(int i=0;i<V;i++)
	   cout<<distance[i]<<" ";
}
void addEdge(vector<int> adj[], int u, int v,int w){
    adj[u].push_back(v);
    weight[u][v]=w;
}

int main() 
{ 
	int V =6;
	memset(weight,INT_MAX,sizeof(weight));
	vector<int> adj[V];
	addEdge(adj,0, 1,2);
    addEdge(adj,1, 2,3); 
    addEdge(adj,2, 3,6); 
    addEdge(adj,0, 4,1); 
    addEdge(adj,4, 2,2);
	addEdge(adj,4, 5,4); 
	addEdge(adj,5, 3,1); 
//	cout<<weight[0][1]<<endl;
    cout<<"The adjacency list of matrix..\n";
	for(int i=0;i<V;i++)
	{
		cout<<i<<" | ";
		for(int v:adj[i])
		   cout<<v<<" ";
		cout<<endl;
	}
    cout << "\n\nThe shortest path in DAG\n"; 
    shortestPath(adj,V);
	return 0; 
} 

