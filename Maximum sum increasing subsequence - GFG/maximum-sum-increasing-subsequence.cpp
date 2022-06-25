// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    set<int> s;
	    for(int i=0;i<n;i++){
	        s.insert(arr[i]);
	    }
	    int sum =0;
	    vector<int> res(s.begin(),s.end());
	    vector<vector<int>> dp(n+1,vector<int>(res.size()+1,0));
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=res.size();j++){
	            if(arr[i-1]==res[j-1]){
	                dp[i][j] = arr[i-1]+dp[i-1][j-1];
	                sum = max(sum,dp[i][j]);
	            }
	            else{
	                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    return sum;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends