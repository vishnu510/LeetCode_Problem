class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int finalSum =0;
        for(int i=0;i<nums.size();i++){
            int currSum = sum-finalSum;
            if(finalSum ==(currSum-nums[i])){
                return i;
            }
            else{
                finalSum+=nums[i];
            }
        }
        return -1;
    }
};