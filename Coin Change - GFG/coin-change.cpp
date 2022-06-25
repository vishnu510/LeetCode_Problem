// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    long long solve(int S[], int m, int n,vector<vector<long long>>& dp){
        if(dp[m][n]!=-1) {
            return dp[m][n];
        }
        if(n==0) return 1;
        if(m==0) return 0;
        if(S[m-1]<=n){
            return dp[m][n] = solve(S,m,n-S[m-1],dp) + solve(S,m-1,n,dp);
        }
        return dp[m][n] = solve(S,m-1,n,dp);
    }
    long long int count(int S[], int m, int n) {

        // code here.
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,-1));
        solve(S,m,n,dp);
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends