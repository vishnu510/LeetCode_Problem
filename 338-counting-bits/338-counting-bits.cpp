class Solution {
public:
    vector<int> countBits(int n) {
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i/2] + i%2;
    }
    vector<int> ans;
    for(int i=0;i<=n;i++){
          ans.push_back(dp[i]);
    }
    return ans;
    }
};