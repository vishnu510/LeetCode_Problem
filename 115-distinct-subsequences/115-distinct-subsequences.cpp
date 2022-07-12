class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned int>> dp(t.size()+1,vector<unsigned int>(s.size()+1));
        
        for(int i=0;i<s.size();i++){
            dp[0][i] =1;
        }
        for(int i=1;i<=t.size();i++){
            
            for(int j=1;j<=s.size();j++){
                
                if(t[i-1]==s[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];

                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};