#include<bits/stdc++.h> 
using namespace std; 

int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V];
        bool inMST[V];
        
        for(int i=0;i<V;i++)
        {
            key[i]=INT_MAX;
            inMST[i]=false;
        } 
        key[0]=0;
        int result=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        for(int count=0;count<V;count++)
        {
            auto u=pq.top();
           while(inMST[u.second]==true)
           {
               pq.pop();
               u=pq.top();
           }
           pq.pop();
            inMST[u.second]=true;
            result+=u.first;
            for(auto x: adj[u.second])
            {
                if(!inMST[x[0]])
                {
                    key[x[0]]=min(key[x[0]],x[1]);
                    pq.push({x[1],x[0]});
                }
            }
        }
        return result;
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
	addEdge(adj,0, 1,5);
    addEdge(adj,0, 2,8); 
    addEdge(adj,1, 3,15); 
    addEdge(adj,1, 2,10); 
    addEdge(adj,2, 3,20);
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
    cout<<"\nThe minimum cost Spanning tree by Prism's is \n";
	cout<<spanningTree(V,adj); 
	return 0; 
} 
//Expected Time Complexity: O(ElogV).

