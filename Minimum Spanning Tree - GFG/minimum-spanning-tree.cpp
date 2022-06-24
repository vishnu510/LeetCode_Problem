// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.

	
	int findParent(int i,vector<int>& parent){
	    if(i==parent[i]){
	        return i;
	    }
	    else{
	        return findParent(parent[i],parent);
	    }
	}
	
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> disJointSet(V);
        for(int i=0;i<V;i++){
            disJointSet[i] =i;
        }
        vector<int> rank(V,1);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<V;i++){
            vector<vector<int>> v = adj[i];
            for(auto x:v){
                pq.push({x[1],{i,x[0]}});
            }
        }
        int count =0,minCost =0;
        while(count<V-1){
            int distance = pq.top().first;
            int element1 = pq.top().second.first;
            int element2 = pq.top().second.second;
            pq.pop();
            int point1 = findParent(element1,disJointSet);
            int point2 = findParent(element2,disJointSet);
            if(point1!=point2){
                if(rank[point1]>rank[point2]){
                    disJointSet[point1] = point2;
                }
                else if(rank[point1]<rank[point2]){
                    disJointSet[point2] = point1;
                }
                else{
                    disJointSet[point1] = point2;
                    rank[point2]++;
                }
                minCost+=distance;
                count++;
            }
        }
        return minCost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends