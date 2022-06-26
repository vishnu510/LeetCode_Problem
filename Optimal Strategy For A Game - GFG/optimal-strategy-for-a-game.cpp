// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int dp[1001][1001];
    long long solution(int l,int r,int arr[]){
        if(l>=r)return 0;
        if(r-l==1)return max(arr[l],arr[r]); 
        if(dp[l][r]!=-1)return dp[l][r];
        if((r-l+1)%2==0){
            return dp[l][r]=max(arr[l]+solution(l+1,r,arr),arr[r]+solution(l,r-1,arr));
        }
        else {
            return dp[l][r]=min(solution(l+1,r,arr),solution(l,r-1,arr));
        }
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        memset(dp,-1,sizeof(dp));
        return solution(0,n-1,arr);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends