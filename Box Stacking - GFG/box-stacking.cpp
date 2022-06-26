// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int dp[702];
    int solve(vector<vector<int>>& v,int n,int idx){
        int ans = 0;
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(int i=0;i<n;i++){
            if(v[idx][0]>v[i][0] and v[idx][1]>v[i][1]){
                ans = max(ans,solve(v,n,i)+v[i][2]);
            }
        }
        return dp[idx] = ans;
    }
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> box;
        for(int i=0;i<n;i++){
            box.push_back({height[i],width[i],length[i]});
            box.push_back({width[i],height[i],length[i]});
            box.push_back({length[i],width[i],height[i]});
            box.push_back({width[i],length[i],height[i]});
            box.push_back({length[i],height[i],width[i]});
            box.push_back({height[i],length[i],width[i]});
        }
        int ans =0;
        for(int i=0;i<6*n;i++){
            ans = max(ans,solve(box,6*n,i)+box[i][2]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends