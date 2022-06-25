class Solution {
public:
   bool canPartition(vector<int>& nums){
       int sum =0;
       for(int i=0;i<nums.size();i++){
           sum+=nums[i];
       }
       if(sum & 1){
           return false;
       }
       sum = sum/2;
       vector<vector<bool>> dp(sum+1,vector<bool>(nums.size()+1,false));
       for(int i=0;i<nums.size();i++){
           dp[0][i]= true;
       }
       for(int i=1;i<=sum;i++){
           dp[i][0]= false;
       }
       for(int i=1;i<=sum;i++){
           for(int j=1;j<nums.size();j++){
               dp[i][j] = dp[i][j-1];
               if(i-nums[j-1]>=0){
                   dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
               }
           }
       }
       return dp[sum][nums.size()-1];
   }
};