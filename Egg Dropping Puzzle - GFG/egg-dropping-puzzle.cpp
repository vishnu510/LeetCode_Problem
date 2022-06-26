// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int helper(int k,int n,vector<vector<int>>& dp){
    if(n==0||n==1) return n;
    if(k==1) return n;
    if(dp[k][n]!=-1) return dp[k][n];
    int mn = INT_MAX,low=0,high =n, temp=0;
    while (low<=high)
    {
        int mid = (low+high)/2;
        int left = helper(k-1,mid-1,dp);
        int right = helper(k,n-mid,dp);
        temp = 1 + max(left,right);
        if(left<right){
            low = mid+1;
        }
        else{
            high =mid-1;
        }
        mn = min(mn,temp);
    }
    return dp[k][n] = mn;
}
    int eggDrop(int k, int n) 
    {
        // your code here
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return helper(k,n,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends