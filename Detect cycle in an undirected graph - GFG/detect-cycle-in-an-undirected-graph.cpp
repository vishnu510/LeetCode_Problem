// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool getCycle(int src,vector<int>& vis,vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] =1;
        while(!q.empty()){
            int node = q.front().first;
            int nod = q.front().second;
            q.pop();
            for(auto i:adj[node]){
                if(vis[i]==0){
                    vis[i] =1;
                    q.push({i,node});
                }
                else if(vis[i]==1 && nod!=i){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V+1,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(getCycle(i,visited,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends