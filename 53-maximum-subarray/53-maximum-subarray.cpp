class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
    int sum = 0; 
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
      
        if(nums[i] > sum)
            sum = nums[i];
        
        
        maxSum = max(maxSum,sum);
    }
    return maxSum;
        
    }
};