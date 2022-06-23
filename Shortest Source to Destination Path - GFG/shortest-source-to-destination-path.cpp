// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0) return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        int s = 0,e=0,distance =0;
        while(!q.empty()){
            distance = q.front().first;
            s = q.front().second.first;
            e = q.front().second.second;
            q.pop();
            if(s==X && e==Y) return distance;
            
            if(s+1<N && A[s+1][e]==1){
                    q.push({distance+1,{s+1,e}});
                    A[s+1][e]=0;
            }
            if(s-1>=0 && A[s-1][e]==1){
                    q.push({distance+1,{s-1,e}});
                    A[s-1][e]=0;
            }
            if(e+1<M && A[s][e+1]==1){
                    q.push({distance+1,{s,e+1}});
                    A[s][e+1]=0;
            }
            if(e-1>=0 && A[s][e-1]==1){
                    q.push({distance+1,{s,e-1}});
                    A[s][e-1]=0;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends