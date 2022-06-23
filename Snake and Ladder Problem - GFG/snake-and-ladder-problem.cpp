// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int ans = INT_MAX;
    void dfs(int i,vector<int>&adj,int move,vector<int>& vis){
        if(i>30) return;
        
        if(i==30){
            ans = min(ans,move);
        }
        if(vis[i]<move) return;
        vis[i] = move;
        if(adj[i]!=0){
            dfs(adj[i],adj,move,vis);
            return;
        }
        dfs(i+1,adj,move+1,vis);
        dfs(i+2,adj,move+1,vis);
        dfs(i+3,adj,move+1,vis);
        dfs(i+4,adj,move+1,vis);
        dfs(i+5,adj,move+1,vis);
        dfs(i+6,adj,move+1,vis);
    }
    
    int minThrow(int N, int arr[]){
        // code here
        vector<int> adj(31,0);
        for(int i=0;i<2*N;i+=2){
            adj[arr[i]]=arr[i+1];
        }
        vector<int> vis(31,INT_MAX);
        ans = INT_MAX;
        dfs(1,adj,0,vis);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends