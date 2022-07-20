class Solution {
public:
    
    int getProd(int n,int curr,vector<vector<int>>& dp){
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=curr;j++){
                if(i==0 || j==0){
                    dp[i][j] = 1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=curr;j++){
                if(i<j){
                    dp[i][j] = dp[i][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],j*dp[i-j][j]);
                }
            }
        }
        return dp[n][curr];
    }
    int integerBreak(int n) {
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return getProd(n,n-1,dp);
    }
};