class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int max_1 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(i==0) dp[i] =1;
            else{
                for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                  dp[i] = max(dp[i],dp[j]+1);
                }
                else{
                    dp[i] = max(dp[i],1);
                }
            }
            }
            max_1 = max(max_1,dp[i]);
        }
        return max_1;
    }
};