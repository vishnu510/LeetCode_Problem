// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	bool dfs(int src,stack<int>& st,vector<int>& vis, int v,vector<int> adj[]){
	    vis[src] =1;
	    for(auto it:adj[src]){
	        if(vis[it]==0){
	            dfs(it,st,vis,v,adj);
	        }
	    }
	    st.push(src);
	}
	
	void dfsTrav(int i,vector<int> & vis,vector<int> res[]){
	    vis[i] =1;
	    for(auto it:res[i]){
	        if(vis[it]==0){
	            dfsTrav(it,vis,res);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        int ans =0;
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,st,vis,V,adj);
            }
        }
        vector<int> res[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                res[it].push_back(i);
            }
        }
        vector<int> visited(V);
        while(!st.empty()){
            int t = st.top();
            st.pop();
            if(visited[t]==0){
                ans++;
                dfsTrav(t,visited,res);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends