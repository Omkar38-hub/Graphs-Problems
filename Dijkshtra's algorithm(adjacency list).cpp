#include<bits/stdc++.h> 
using namespace std; 


void printPath(int parent[], int j)
{
      
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
  
    printPath(parent, parent[j]);
  
    printf("-> %d ", j);
}
void printMST(int src,int distance[],int parent[],int V)
{
	for(int i=0;i<V;i++)
	{
		cout<<"\n"<<src<<" - "<<i<<" = "<< distance[i]<<endl<<"Path: "<<src;
		printPath(parent,i);
	}
}
void Dijkstra(int V, vector<vector<int>> adj[],int src)
    {
        int distance[V];
        bool inMST[V];
        
        for(int i=0;i<V;i++)
        {
            distance[i]=INT_MAX;
            inMST[i]=false;
        } 
        distance[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});// pair of weight and vertices
        int parent[V]; 
        parent[src]=-1;
        while(!pq.empty())
		{
          auto u=pq.top();
          pq.pop();
          if(inMST[u.second])
            continue;
          inMST[u.second]=true;
          for(auto x: adj[u.second])
            {
                if(!inMST[x[0]] && distance[x[0]]>distance[u.second]+x[1])
                {
                	distance[x[0]]=distance[u.second]+x[1];
                	parent[x[0]]=u.second;
                    pq.push({distance[u.second]+x[1],x[0]});
                }
            }
        }
        printMST(src,distance,parent,V);
    }

void addEdge(vector<vector<int>>adj[], int u, int v,int w){
	vector<int>t1,t2;
	t1.push_back(v);
	t1.push_back(w);
    adj[u].push_back(t1);
    t2.push_back(u);
	t2.push_back(w);
    adj[v].push_back(t2);
}

int main() 
{ 
	int V =4;
	vector<vector<int>>adj[V];
	addEdge(adj,0, 1,50);
    addEdge(adj,0, 2,100); 
    addEdge(adj,2, 3,20); 
    addEdge(adj,1, 2,30); 
    addEdge(adj,1, 3,200);
    cout<<"The adjacency list of matrix..\n";
	for(int i=0;i<V;i++)
	{
		cout<<i<<" | ";
		for(auto v:adj[i])
		  {
		  	 cout<<"(";
		  	for(auto x: v)
		  	  cout<<x<<" ";
		  	cout<<"),";
		  }
		cout<<endl;
	}
    cout<<"\nThe Dijkshtra's shortest Path' is \n";
	Dijkstra(V,adj,0);  
	return 0; 
} 
//Expected Time Complexity: O((V+E)logV).

