// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool getCycle(int node,vector<int>& vis,vector<int> adj[],int par,vector<int>& dvis){
        vis[node] = 1;
        dvis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(getCycle(it,vis,adj,node,dvis)){
                    return true;
                }
            }
            else if(dvis[it]){
                return true;
            }
        }
        dvis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0),dvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i] && getCycle(i,vis,adj,-1,dvis)){
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends