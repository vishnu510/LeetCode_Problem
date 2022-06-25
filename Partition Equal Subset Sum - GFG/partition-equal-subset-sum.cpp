// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool equalPartition(int n, int nums[])
    {
        // code here
        int sum =0;
       for(int i=0;i<n;i++){
           sum+=nums[i];
       }
       if(sum & 1){
           return false;
       }
       sum = sum/2;
       vector<vector<bool>> dp(sum+1,vector<bool>(n+1,false));
       for(int i=0;i<n;i++){
           dp[0][i]= true;
       }
       for(int i=1;i<=sum;i++){
           dp[i][0]= false;
       }
       for(int i=1;i<=sum;i++){
           for(int j=1;j<n;j++){
               dp[i][j] = dp[i][j-1];
               if(i-nums[j-1]>=0){
                   dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
               }
           }
       }
       return dp[sum][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends