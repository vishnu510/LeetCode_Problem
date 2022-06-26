// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long helper(int n,vector<int>& dp){
        if(n<0){
            return 0;
        }
        if(n==0||n==1){
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n] = (helper(n-3,dp)+helper(n-2,dp)+helper(n-1,dp))%1000000007;
        return dp[n];
    }
    
    long long countWays(int n)
    {
        
        // your code here
        vector<int> dp(n+1,-1);
        return helper(n,dp);
        
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends