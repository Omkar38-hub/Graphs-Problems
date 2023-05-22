#include<bits/stdc++.h>
using namespace std;
void topological(bool visited[],int s,stack<int>&st,vector<int> adj[])
    {
        visited[s]=true;
        for(int x: adj[s])
        {
            if(!visited[x])
               topological(visited,x,st,adj);
        }
        st.push(s);
    }

void DFS(bool visited[],int s,vector<int> adj[])
    {
        visited[s]=true;
        cout<<s<<" ";
        for(int x: adj[s])
        {
            if(!visited[x])
                DFS(visited,x,adj);
        }
    }
int kosaraju(int V, vector<int> adj[])
    {
        bool visited[V]={false};
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
               topological(visited,i,st,adj); // step 1
        }
        vector<int>v;
        cout<<"The topological sort is ";
        while(!st.empty())
        {
            v.push_back(st.top());
            cout<<st.top()<<" ";
            st.pop();
        }
        vector<int> a[V];
        for(int i=0;i<V;i++)
        {
            for(int x: adj[i])
            {
                a[x].push_back(i);
            }
        }
        int count=0;
        bool vis[V]={false};
        cout<<"\n\nThe connected components of graph are\n";
        for(int i=0;i<v.size();i++)
        {
            if(!vis[v[i]])
            {
                DFS(vis,v[i],a);
                cout<<endl;
                count++;
            }
        }
        return count;
    }

void addEdge(vector<int>adj[],int u,int v)  
{
	adj[u].push_back(v);
}
int main()
{
  	int V=5;
  	vector<int>adj[V];
  	addEdge(adj,0,2);
  	addEdge(adj,0,3);
  	addEdge(adj,3,4);
  	addEdge(adj,1,0);
  	addEdge(adj,2,1);
    cout<<"\n\nThe number of stongly connected components are "<<kosaraju(V,adj);
    return 0;
}  
    
